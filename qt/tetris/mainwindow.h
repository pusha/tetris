#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
//    const int gray = 0xb2b0aa;

private slots:


    void on_btnRestart_clicked();

private:
    void update_ui();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
