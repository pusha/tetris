#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{

//  this->ui->spinCount->setValue(this->ui->renderArea->stepCount());
} //-update_ui()



//------------------------------------------------------------------------------
/**
 * @brief MainWindow::on_btnRestart_clicked
 * @author  pusha
 */
void MainWindow::on_btnRestart_clicked()
{
  QApplication::quit();
}

