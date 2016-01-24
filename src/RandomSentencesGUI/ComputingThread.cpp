#include "ComputingThread.h"

ComputingThread::ComputingThread(WordsGenerator * pwg, std::string pphrase, unsigned long long piterations) {
    wg = pwg;
    phrase = pphrase;
    iterations = piterations;
}

ComputingThread::~ComputingThread() {

}

void ComputingThread::run() {
    Stats stats = wg->studySentence(phrase, iterations);

    emit computingEnded(stats);

    /// on libere les ressources
    delete wg;
    wg = NULL;
}
