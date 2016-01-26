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
        std::ostringstream    * sortie;
        LoadThread              mProgressThread;

    signals:
        void computingEnded(Stats);
        void computingProgressed(double percent);

    private slots:
        void computingProgressed_s(double percent);

    public:
        ComputingThread(WordsGenerator *, std::string, unsigned long long, std::ostringstream&);
        virtual ~ComputingThread();

        void run();
        QThread & getProgThread();
};

#endif // COMPUTINGTHREAD_H
