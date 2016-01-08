#include <QtGui>
#include <QFileDialog>

#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionQuitter_triggered() {
    close();
}

void MainWindow::on_browsePrincipal_clicked() {
    // Ouvre le menu de selection de fichier et stocke le chemin
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier principal", QString(), "Formats supportés (*.txt *.html *.pdf);;Autre (*)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    ui->displayPrincipal->setText(fichier);
}


void MainWindow::on_browseIgnore_clicked() {
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier de mots à ignorer", QString(), "Fichier de configuration (*.conf)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    ui->displayIgnore->setText(fichier);
}

void MainWindow::on_browseSeparator_clicked() {
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier de séparateurs", QString(), "Fichier de configuration (*.conf)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    ui->displaySeparator->setText(fichier);
}
