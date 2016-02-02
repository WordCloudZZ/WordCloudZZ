#include "LoadThread.h"
#include <iostream>
#include <string>

LoadThread::LoadThread(std::ostringstream * pflux, unsigned long long piterations) :
    flux(pflux), iterations(piterations) {

}

LoadThread::~LoadThread() {

}

void LoadThread::run() {
    unsigned long long i = 0;
    emit computingProgressed(0);
    while(i<iterations) {
        std::stringstream sstm;
        sstm << "Round " << i+1 << ":";
        std::string chr = sstm.str();
        std::string str = flux->str();
        std::size_t pos = str.rfind(chr);
        if(pos != std::string::npos) {
            emit computingProgressed(i/(double)iterations);
            i++;
        }
        //usleep(20);
    }
}
