#ifndef COMPUTINGTHREAD_H
#define COMPUTINGTHREAD_H

#include <QObject>
#include <QtCore>

#include "WordsGenerator.h"

namespace Ui {
class ComputingThread;
}

class ComputingThread : public QThread {
    Q_OBJECT
    protected:
        WordsGenerator * wg;
        std::string phrase;
        unsigned long long iterations;

    signals:
        void computingEnded(Stats);

    public:
        ComputingThread(WordsGenerator *, std::string pphrase, unsigned long long piterations);
        virtual ~ComputingThread();

        void run();
};

#endif // COMPUTINGTHREAD_H
