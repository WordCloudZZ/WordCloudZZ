// Includes Qt
#include "mainwindow.h"
#include <QApplication>

// Includes c++
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string filePath = "";

    QApplication a(argc, argv); // Objet de l'app
    MainWindow w; // Fenetre principale
    w.show(); // Affiche la fenetre

    return a.exec();
}
