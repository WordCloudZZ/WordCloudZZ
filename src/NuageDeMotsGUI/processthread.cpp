#include "processthread.h"

/**
 * @brief Thread constructor
 * @param p The main file to process
 * @param i The file containing words to ignore
 * @param s The separators file
 */
ProcessThread::ProcessThread(std::string p, std::string i, std::string s) {
    qRegisterMetaType<stringVec>("stringVec"); // Registering to use it in signal connect

    principal = p;
    ignore = i;
    separator = s;

    /// Creating the filereader
    fr = new FileReader<Hashtable>(ignore, separator);
}

/**
 * @brief Thread destructor
 */
ProcessThread::~ProcessThread() {
    if(fr != NULL) {
        delete fr;
    }
}

/**
 * @brief Run method of the thread
 */
void ProcessThread::run() {
    std::cout << "Debut du thread" << std::endl;

    if(fr != NULL) {
        std::cout << "Analyse du texte" << std::endl;
        fr->read(principal);

        std::cout << "Tri des mots" << std::endl;

        /// Store the results in a string vector
        stringVec list;
        list = fr->printStudyTable();

        std::cout << "Fin de l'extraction" << std::endl;

        /// The signal is emitted
        emit processEnd(list);

        std::cout << "Signal emis" << std::endl;
    } else {
        std::cout << "Erreur avec la creation du FileReader" << std::endl;
        stringVec list; list.push_back("");
        emit processEnd(list);
    }

    std::cout << "Fin du thread" << std::endl;
}
