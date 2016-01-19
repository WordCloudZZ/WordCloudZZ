#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    buff0 = "";
    buff1 = "";
    buff2 = "";

    ui->displayIgnore->setText("Fichier par défaut");
    ui->displaySeparator->setText("Fichier par défaut");
    ui->displayPrincipal->setText("Fichier exemple");
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
        std::cout << "Modification -> Fichier : " << buff0 << std::endl;
    }
}


void MainWindow::on_browseIgnore_clicked() {
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier de mots à ignorer", QString(), "Fichier de configuration (*.conf)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    if(fichier.length() != 0) {
        buff1 = fichier.toStdString();
        ui->displayIgnore->setText(fichier);
        std::cout << "Modification -> Ignore : " << buff1 << std::endl;
    }
}

void MainWindow::on_browseSeparator_clicked() {
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier de séparateurs", QString(), "Fichier de configuration (*.conf)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    if(fichier.length() != 0) {
        buff2 = fichier.toStdString();
        ui->displaySeparator->setText(fichier);
        std::cout << "Modification -> Separateur : " << buff2 << std::endl;
    }
}

void MainWindow::on_defaultIgnore_clicked() {
    // Remet le fichier a ignorer par defaut
    if(0 != buff1.compare(buff[1])) {
        buff1 = buff[1];
        std::cout << "Par defaut -> Ignore : " << buff1 << std::endl;

        ui->displayIgnore->setText("Fichier par défaut");
    }
}

void MainWindow::on_defaultSeparator_clicked() {
    // Remet le fichier separateur par defaut
    if(0 != buff2.compare(buff[2])) {
        buff2 = buff[2];
        std::cout << "Par defaut -> Separateur : " << buff2 << std::endl;

        ui->displaySeparator->setText("Fichier par défaut");
    }
}

void MainWindow::on_extract_clicked() {
    // Lancer l'extraction et faire afficher dans textZone
    lock_buttons(); // Bloque les boutons
    ui->centralWidget->setCursor(Qt::BusyCursor);

    Sleep(10000);

    fr = new FileReader<Hashtable>(buff1, buff2);
    fr->read(buff0);
    fr->sortTable();

    ui->textZone->setText(QString::fromStdString(fr->stringStudyTable())); // Il faut caster en QString

    std::cout << "On a extrait" << std::endl;

    delete fr;

    unlock_buttons(); // Debloque les boutons
    ui->centralWidget->setCursor(Qt::ArrowCursor);
}

void MainWindow::lock_buttons() {
    ui->browseIgnore->setEnabled(false);
    ui->browsePrincipal->setEnabled(false);
    ui->browseSeparator->setEnabled(false);
    ui->defaultIgnore->setEnabled(false);
    ui->defaultSeparator->setEnabled(false);

    ui->extract->setEnabled(false);

    std::cout << "Boutons bloques" << std::endl;
}

void MainWindow::unlock_buttons() {
    ui->browseIgnore->setEnabled(true);
    ui->browsePrincipal->setEnabled(true);
    ui->browseSeparator->setEnabled(true);
    ui->defaultIgnore->setEnabled(true);
    ui->defaultSeparator->setEnabled(true);

    ui->extract->setEnabled(true);

    std::cout << "Boutons debloques" << std::endl;
}
