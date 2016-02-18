#include "processthread.h"


ProcessThread::ProcessThread(std::string p, std::string s, std::string i) {
    qRegisterMetaType<stringVec>("stringVec");

    principal = p;
    separator = s;
    ignore = i;

    /// First check if the file exist for later use
    if(QFile::exists(QString::fromStdString(ignore)) && QFile::exists(QString::fromStdString(separator))) {
        fr = new FileReader<Hashtable>(ignore, separator);
    } else {
        std::cout << "Erreur : un des fichiers de configuration est manquant" << std::endl;
        fr = NULL; /// This will prevent the thred to execute
    }
}

ProcessThread::~ProcessThread() {
    if(fr != NULL) {
        delete fr;
    }
}

void ProcessThread::run() {
    std::cout << "Debut du thread" << std::endl;

    if(fr != NULL) {
        if(QFile::exists(QString::fromStdString(principal))) {
            std::cout << "Analyse du texte" << std::endl;
            fr->read(principal);

            std::cout << "Tri des mots" << std::endl;

            /// Store the results un a string vector
            stringVec list;
            list = fr->printStudyTable();

            std::cout << "Fin de l'extraction" << std::endl;

            /// The signal is emitted
            emit processEnd(list);
        } else { /// The main file is missing
            std::cout << "Erreur : le fichier principal n'existe pas" << std::endl;
        }
    } else {
        std::cout << "Erreur avec la creation du FileReader" << std::endl;
    }

    std::cout << "Fin du thread" << std::endl;
}
