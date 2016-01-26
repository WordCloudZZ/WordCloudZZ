#include "ComputingThread.h"

ComputingThread::ComputingThread(WordsGenerator * pwg, std::string pphrase, unsigned long long piterations, std::ostringstream & p_sortie) :
    wg(pwg), phrase(pphrase), iterations(piterations), buf(), flux(), mProgressThread(&flux,iterations) {
    sortie = &p_sortie;
    QObject::connect(&mProgressThread, SIGNAL(computingProgressed(double)), this, SLOT(computingProgressed_s(double)));
}

ComputingThread::~ComputingThread() {

}

void ComputingThread::run() {
    mProgressThread.start(QThread::LowPriority);
    Stats stats = wg->studySentence(phrase, iterations, flux);
    mProgressThread.wait();
    *sortie << flux.str();
    emit computingEnded(stats);
}

void ComputingThread::computingProgressed_s(double percent) {
    emit computingProgressed(percent);
}

QThread & ComputingThread::getProgThread() {
    return mProgressThread;
}
