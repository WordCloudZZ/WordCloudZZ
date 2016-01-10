#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    buff0 = "";
    buff1 = "";
    buff2 = "";
}

MainWindow::~MainWindow() {
    delete ui;
    delete fr;
    delete buff;
}

void MainWindow::setDefaultFiles(const std::string & f, const std::string & i, const std::string & s) {
    buff[0] = f;
    buff[1] = i;
    buff[2] = s;

    buff0 = buff[0];
    buff1 = buff[1];
    buff2 = buff[2];

    std::cout << "Par defaut\n" << "Principal : " << buff0 << "\nIgnore : " << buff1 << "\nSeparator : " << buff2 << std::endl;
}

void MainWindow::on_actionQuitter_triggered() {
    delete ui;
    close();
}

void MainWindow::on_browsePrincipal_clicked() {
    // Ouvre le menu de selection de fichier et stocke le chemin
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier principal", QString(), "Formats supportés (*.txt *.html *.pdf);;Autre (*)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    if(fichier.length() != 0) {
        buff0 = fichier.toStdString();
        ui->displayPrincipal->setText(fichier);
        std::cout << "Fichier : " << buff0 << std::endl;
    }
}


void MainWindow::on_browseIgnore_clicked() {
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier de mots à ignorer", QString(), "Fichier de configuration (*.conf)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    if(fichier.length() != 0) {
        buff1 = fichier.toStdString();
        ui->displayIgnore->setText(fichier);
        std::cout << "Ignore : " << buff1 << std::endl;
    }
}

void MainWindow::on_browseSeparator_clicked() {
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier de séparateurs", QString(), "Fichier de configuration (*.conf)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    if(fichier.length() != 0) {
        buff2 = fichier.toStdString();
        ui->displaySeparator->setText(fichier);
        std::cout << "Separateur : " << buff2 << std::endl;
    }
}

void MainWindow::on_defaultIgnore_clicked() {
    // Remet le fichier a ignorer par defaut
    buff1 = buff[1];
    std::cout << "Ignore : " << buff1 << std::endl;
}

void MainWindow::on_defaultSeparator_clicked() {
    // Remet le fichier separateur par defaut
    buff2 = buff[2];
    std::cout << "Separateur : " << buff2 << std::endl;
}

void MainWindow::on_extract_clicked() {
    // Lancer l'extraction et faire afficher dans textZone
    fr = new FileReader<Hashtable>(buff1, buff2);
    fr->read(buff0);
    fr->sortTable();

    ui->textZone->setText(QString::fromStdString(fr->stringStudyTable())); // Il faut caster en QString

    std::cout << "On a extrait" << std::endl;

    delete fr;
}
