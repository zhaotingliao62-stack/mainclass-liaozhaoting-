#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainClass; }
QT_END_NAMESPACE

class MainClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainClass(QWidget *parent = nullptr);
    ~MainClass() override;

private slots:
    void on_OpenSignal_button_clicked();

private:
    bool loadSignal(const QString &filePath);
    void showReadError(const QString &filePath, const QString &reason);
    Ui::MainClass *ui;
};

#endif

