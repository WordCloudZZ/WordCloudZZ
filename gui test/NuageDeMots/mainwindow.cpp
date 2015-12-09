#include <QtGui>
#include <QFileDialog>

#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionQuitter_triggered() {
    close();
}

// Bouton de choix du fichier principal
void MainWindow::on_pushButton_2_released() {
    // Ouvre le menu de selection de fichier et stocke le chemin
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Document texte (*.txt);;Autre (*)");
    std::cout << "J'ai trouvé " << fichier.toStdString() << std::endl; // Affiche le résultat
}
