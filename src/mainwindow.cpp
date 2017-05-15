#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QDebug>

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
    QImage img = ui->widgetDraw->image().scaled(20, 20);

    double gray;

    for ( int row = 1; row <= img.height(); ++row )
    {

        for ( int col = 1; col <= img.width(); ++col )
        {
            QColor clrCurrent( img.pixel( row, col ) );

            gray = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue() + clrCurrent.alpha())/(4 * 255.0);

            qDebug() << gray;

        }
    }
}
