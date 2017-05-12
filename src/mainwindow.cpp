#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QImage>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->widgetDraw->clearImage();
}

void MainWindow::on_pushButtonOk_clicked()
{
    QImage image_mini = ui->widgetDraw->image().scaled(20, 20, Qt::KeepAspectRatio);
}
