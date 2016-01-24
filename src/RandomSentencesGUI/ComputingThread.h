#ifndef COMPUTINGTHREAD_H
#define COMPUTINGTHREAD_H

#include <QObject>
#include <QtCore>
#include <sstream>

#include "WordsGenerator.h"
#include "LoadThread.h"

namespace Ui {
class ComputingThread;
}

class ComputingThread : public QThread {
    Q_OBJECT
    protected:
        WordsGenerator        * wg;
        std::string             phrase;
        unsigned long long      iterations;
        std::stringbuf          buf;
        std::ostringstream      flux;
        LoadThread              mProgressThread;

    signals:
        void computingEnded(Stats);
        void computingProgressed(double percent);

    private slots:
        void computingProgressed_s(double percent);

    public:
        ComputingThread(WordsGenerator *, std::string pphrase, unsigned long long piterations);
        virtual ~ComputingThread();

        void run();
        QThread & getProgThread();
};

#endif // COMPUTINGTHREAD_H
