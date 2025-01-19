#include "mainwindow.h"

#include <QApplication>
#include "Service.h"

int main(int argc, char *argv[]) {
    QApplication mainApplication(argc, argv);
    QCoreApplication::setApplicationName("Movie Rental");
    Service service;
    MainWindow mainWindow(service);
    mainWindow.show();
    return mainApplication.exec();
}

