
#include <QApplication>

#include "ann.h"
#include "mainwindow.h"


int main(int argc, char *argv[])
{

    QCoreApplication::setOrganizationName("Blog do Eduardo");
    QCoreApplication::setOrganizationDomain("www.eduardomartins.site");
    QCoreApplication::setApplicationName("Number Recognition");

    ann();

    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
