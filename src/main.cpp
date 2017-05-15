
#include <QApplication>

#include "ann.h"
#include "src/mainwindow.h"


int main(int argc, char *argv[])
{

    QCoreApplication::setOrganizationName("Blog do Eduardo");
    QCoreApplication::setOrganizationDomain("www.eduardomartins.site");
    QCoreApplication::setApplicationName("Number Recognition");
    QApplication app(argc, argv);

    ANN *network = &ANN::getInstance();

    MainWindow window;
    window.show();
    return app.exec();
}
