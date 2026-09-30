#include "mainclass.h"
#include "ui_mainclass.h"

#include <QDataStream>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QStandardPaths>

namespace {
QVector<QColor> graphColors()
{
    return {QColor("#1769aa"), QColor("#e74c3c"), QColor("#27ae60"),
            QColor("#8e44ad"), QColor("#f39c12"), QColor("#16a085")};
}
}

MainClass::MainClass(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainClass)
{
    ui->setupUi(this);
    ui->Grapf_qcustomplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->Grapf_qcustomplot->legend->setVisible(true);
    ui->Grapf_qcustomplot->xAxis->setLabel("Time (s)");
    ui->Grapf_qcustomplot->yAxis->setLabel("Signal (raw)");
}

MainClass::~MainClass()
{
    delete ui;
}

void MainClass::showReadError(const QString &filePath, const QString &reason)
{
    QMessageBox::warning(this, tr("Read error"),
                         tr("Cannot read:\n%1\n\n%2").arg(filePath, reason));
}

bool MainClass::loadSignal(const QString &filePath)
{
    bool sampleRateOk = false;
    bool channelCountOk = false;
    const int sampleRate = ui->SampleRate_edit->text().toInt(&sampleRateOk);
    const int channelCount = ui->ChannelsCount_edit->text().toInt(&channelCountOk);
    if (!sampleRateOk || sampleRate <= 0 || !channelCountOk || channelCount <= 0) {
        QMessageBox::warning(this, tr("Invalid parameters"),
                             tr("SampleRate and Channels count must be positive integers."));
        return false;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        showReadError(filePath, file.errorString());
        return false;
    }

    const qint64 frameBytes = channelCount * qint64(sizeof(qint16));
    if (file.size() < frameBytes || file.size() % frameBytes != 0) {
        showReadError(filePath,
                      tr("File size does not match %1 channel(s) of 16-bit data.")
                          .arg(channelCount));
        return false;
    }

    QDataStream stream(&file);
    stream.setByteOrder(QDataStream::LittleEndian);
    const qsizetype frameCount = file.size() / frameBytes;
    QVector<double> time(frameCount);
    QVector<QVector<double>> channels(channelCount);
    for (auto &channel : channels)
        channel.reserve(frameCount);

    for (qsizetype frame = 0; frame < frameCount; ++frame) {
        time[frame] = double(frame) / sampleRate;
        for (int channel = 0; channel < channelCount; ++channel) {
            qint16 value = 0;
            stream >> value;
            channels[channel].append(value);
        }
    }

    ui->Grapf_qcustomplot->clearGraphs();
    const QVector<QColor> colors = graphColors();
    for (int channel = 0; channel < channelCount; ++channel) {
        QCPGraph *graph = ui->Grapf_qcustomplot->addGraph();
        graph->setName(channelCount == 1
                           ? QFileInfo(filePath).fileName()
                           : tr("Channel %1").arg(channel + 1));
        graph->setPen(QPen(colors[channel % colors.size()], 1));
        graph->setData(time, channels[channel]);
    }

    ui->Grapf_qcustomplot->rescaleAxes();
    ui->Grapf_qcustomplot->replot();
    setWindowTitle(tr("%1 - Signal Viewer").arg(QFileInfo(filePath).fileName()));
    return true;
}

void MainClass::on_OpenSignal_button_clicked()
{
    const QString filePath = QFileDialog::getOpenFileName(
        this, tr("Open signal"),
        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),
        tr("DAT files (*.dat);;All files (*)"));
    if (!filePath.isEmpty())
        loadSignal(filePath);
}

