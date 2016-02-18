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

    qRegisterMetaType<stringVec>("stringVec");

    buff0 = "";
    buff1 = "";
    buff2 = "";

    /// Setting text in the display areas
    ui->displayIgnore->setText("Fichier par défaut");
    ui->displaySeparator->setText("Fichier par défaut");
    ui->displayPrincipal->setText("Fichier exemple");
    ui->nbSelect->setValue(10);
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/nuage.png"));
}


/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow() {
    delete ui;
/*
    if(fr != NULL) {
         delete fr;
    }
*/
/* TODO : warning bizarre quand je fais ca ...
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
    ui->listWidget->clear(); /// Clear the zone before rewriting

    /// Creating the process thread and connect signal
    thread = new ProcessThread(buff0, buff1, buff2);
    QObject::connect(thread, SIGNAL(processEnd(stringVec)), this, SLOT(print_results(stringVec)));
    thread->start(QThread::HighPriority); /// Can be highest also
}

void MainWindow::print_results(stringVec list) {
    unsigned int maxPrint = ui->nbSelect->value(); /// Get the desired printed number
    int maxOccur = QString::fromLatin1(list[list.size()-1].c_str()).split(QRegExp("[/\r\n]"), QString::SplitBehavior::SkipEmptyParts).at(1).toInt();
    int ratio = 1;

    maxPrint = std::min(maxPrint, list.size());
    std::cout << "Affichage des resultats" << std::endl;
    for(unsigned i = 0 ; i < maxPrint ; ++i) {
        QString mot = QString::fromLatin1(list[list.size()-1-i].c_str());
        QStringList qlist = mot.split(QRegExp("[/\r\n]"), QString::SplitBehavior::SkipEmptyParts);
        ui->listWidget->addItem(qlist.at(1)+'\t'+qlist.at(0));
        ui->listWidget->item(i)->setTextAlignment(Qt::AlignJustify);

        /// Determining color
        ratio = 255*qlist[1].toInt()/maxOccur;
        ui->listWidget->item(i)->setBackgroundColor(QColor(std::min(ratio*125/100,255),60,255-ratio,169));
    }

    delete thread; /// Free the thread memory

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
