#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    buff0 = "";
    buff1 = "";
    buff2 = "";

    /// Setting text in the display areas
    ui->displayIgnore->setText("Fichier par défaut");
    ui->displaySeparator->setText("Fichier par défaut");
    ui->displayPrincipal->setText("Fichier exemple");
    ui->nbSelect->setValue(10);
}


/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow() {
    delete ui;
    if(fr != NULL) {
         delete fr;
    }
/* TODO : warning bizarre quand ej fais ca ...
    if(buff != NULL) {
        delete [] buff;
    }
*/
}

/**
 * @brief Set the default files to be used in the app
 * @param f default main file
 * @param i default ignore words file
 * @param s default separator file
 */
void MainWindow::setDefaultFiles(const std::string & f, const std::string & i, const std::string & s) {
    buff[0] = f; /// Main file
    buff[1] = i; /// Ignore words file
    buff[2] = s; /// Separator file

    /// Setting defaults to current
    buff0 = buff[0];
    buff1 = buff[1];
    buff2 = buff[2];

    /// Control print
    std::cout << "Par defaut\n" << "Principal : " << buff0 << "\nIgnore : " << buff1 << "\nSeparator : " << buff2 << std::endl;
}

/**
 * @brief Event to call on 'quit' trigger
 */
void MainWindow::on_actionQuitter_triggered() {
    delete ui;
    close();
}

/**
 * @brief Browsing for the main file
 */
void MainWindow::on_browsePrincipal_clicked() {
    /// Open file selection window
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier principal", QString(), "Formats supportés (*.txt *.html *.pdf);;Autre (*)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    if(fichier.length() != 0) { /// Test if a file is selected
        buff0 = fichier.toStdString();
        ui->displayPrincipal->setText(fichier);
        std::cout << "Modification -> Fichier : " << buff0 << std::endl;
    }
}

/**
 * @brief Browsing for the ignore words file
 */
void MainWindow::on_browseIgnore_clicked() {
    /// Open file selection window
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier de mots à ignorer", QString(), "Fichier de configuration (*.conf)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    if(fichier.length() != 0) {
        buff1 = fichier.toStdString();
        ui->displayIgnore->setText(fichier);
        std::cout << "Modification -> Ignore : " << buff1 << std::endl;
    }
}

/**
 * @brief Browsing for the separator file
 */
void MainWindow::on_browseSeparator_clicked() {
    /// Open file selection window
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier de séparateurs", QString(), "Fichier de configuration (*.conf)");
    //std::cout << "Localise " << fichier.toStdString() << std::endl; // Affiche le résultat
    if(fichier.length() != 0) {
        buff2 = fichier.toStdString();
        ui->displaySeparator->setText(fichier);
        std::cout << "Modification -> Separateur : " << buff2 << std::endl;
    }
}

/**
 * @brief Set ignore words file to default
 */
void MainWindow::on_defaultIgnore_clicked() {
    if(0 != buff1.compare(buff[1])) { /// Controls if the file is not already default
        buff1 = buff[1];
        std::cout << "Par defaut -> Ignore : " << buff1 << std::endl;

        ui->displayIgnore->setText("Fichier par défaut");
    }
}

/**
 * @brief Set separator file to default
 */
void MainWindow::on_defaultSeparator_clicked() {
    if(0 != buff2.compare(buff[2])) { /// Controls if the file is not already default
        buff2 = buff[2];
        std::cout << "Par defaut -> Separateur : " << buff2 << std::endl;

        ui->displaySeparator->setText("Fichier par défaut");
    }
}

/**
 * @brief Extraction process
 */
void MainWindow::on_extract_clicked() {
    lock_controls(); /// Locks controls in the ui to avoid unpredicted behaviours

    ui->centralWidget->setCursor(Qt::BusyCursor); /// Display a loading cursor to the user
    ui->textZone->clear(); /// Clear the zone before rewriting

    unsigned int maxPrint = ui->nbSelect->value(); /// Get the desired printed number
    unsigned int nb = 0; /// The actual number printed in the loop

    /// Creating the filereader and getting the stats on the text
    fr = new FileReader<Hashtable>(buff1, buff2);
    if(fr != NULL) {
        // TODO : mettre les analyses dans un thread, et recup le vector a printer,
        // mais pas sur que ca regle certains soucis
        std::cout << "Analyse du texte" << std::endl;
        fr->read(buff0);

        std::cout << "Tri des mots" << std::endl;
        fr->sortTable();

        /// Prints the result in the large text area
        std::vector<std::string> list;
        list = fr->stringList();

        std::cout << "Affichage des resultats" << std::endl;
        for(std::vector<std::string>::reverse_iterator it = list.rbegin(); it != list.rend() && nb < maxPrint; it++, nb++) {
            ui->textZone->append(QString::fromStdString(*it).toUtf8());
            qApp->processEvents(); // Propage le changement et raffraichit l'affichage
        }

        std::cout << "Fin de l'extraction" << std::endl;

        delete fr; /// Freeing memory
        fr = NULL;
    } else {
        std::cout << "Erreur avec la creation du FileReader" << std::endl;
    }

    unlock_controls(); /// Unlockign controls
    ui->centralWidget->setCursor(Qt::ArrowCursor); /// Reseting cursor to default
}

/**
 * @brief Lock all controls in the ui
 */
void MainWindow::lock_controls() {
    ui->browseIgnore->setEnabled(false);
    ui->browsePrincipal->setEnabled(false);
    ui->browseSeparator->setEnabled(false);
    ui->defaultIgnore->setEnabled(false);
    ui->defaultSeparator->setEnabled(false);
    ui->nbSelect->setEnabled(false);

    ui->extract->setEnabled(false);

    std::cout << "Controles bloques" << std::endl;
}

/**
 * @brief Unlock all controls in the ui
 */
void MainWindow::unlock_controls() {
    ui->browseIgnore->setEnabled(true);
    ui->browsePrincipal->setEnabled(true);
    ui->browseSeparator->setEnabled(true);
    ui->defaultIgnore->setEnabled(true);
    ui->defaultSeparator->setEnabled(true);
    ui->nbSelect->setEnabled(true);

    ui->extract->setEnabled(true);

    std::cout << "Controles debloques" << std::endl;
}
