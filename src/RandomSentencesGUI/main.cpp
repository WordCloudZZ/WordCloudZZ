#include "MainWindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "fr_FR");
    QApplication a(argc, argv);
    a.setApplicationName("Générateur de phrases aléatoires");
    MainWindow w;
    w.show();

    return a.exec();
}
