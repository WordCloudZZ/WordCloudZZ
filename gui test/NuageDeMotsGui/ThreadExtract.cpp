#include "ThreadExtract.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

ThreadExtract::ThreadExtract(std::string mainFile, std::string ignoreFile, std::string separatorFile, unsigned int print) {
    std::cout << "Creation du thread" << std::endl;
    this->mainFile_ = mainFile;
    fr_ = new FileReader<Hashtable>(ignoreFile, separatorFile);
    maxPrint_ = print;
}

ThreadExtract::~ThreadExtract() {
    if(fr_ != NULL)  { /// Memory freeing
        delete fr_;
    }

    std::cout << "Thread detruit" << std::endl;
}

void ThreadExtract::run() {
    std::cout << "Lancement du thread" << std::endl;

    unsigned int nb = 0; /// The actual number of words printed

    ui->lock_buttons(); /// Locks controls in the ui to avoid unpredicted behaviours
    ui->centralWidget->setCursor(Qt::BusyCursor); /// Display a loading cursor to the user
    ui->textZone->clear(); /// Clear the zone before rewriting

    /// Creating the filereader and getting the stats on the text
    if(fr_ != NULL) {
        std::cout << "Analyse du texte" << std::endl;
        fr_->read(mainFile_);
        std::cout << "Tri des mots" << std::endl;
        fr_->sortTable();

        /// Prints the result in the large text area
        std::vector<std::string> list;
        list = fr_->stringList();

        std::cout << "Affichage des resultats" << std::endl;
        ui->textZone->append(QString::fromUtf8("Résultat"));
        for(std::vector<std::string>::reverse_iterator it = list.rbegin(); it != list.rend() && nb < maxPrint; it++, nb++) {
            ui->textZone->append(QString::fromStdString(*it));
            //qApp->processEvents(); // Propage le changement et raffraichit l'affichage
        }

        std::cout << "Fin de l'extraction" << std::endl;
    } else {
        std::cout << "Erreur avec la creation du FileReader" << std::endl;
    }

    ui->unlock_buttons(); /// Unlocking controls
    ui->centralWidget->setCursor(Qt::ArrowCursor); /// Reseting cursor to default

    std::cout << "Fin du thead" << std::endl;
}
