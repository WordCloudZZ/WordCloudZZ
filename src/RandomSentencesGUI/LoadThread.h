#ifndef LOADTHREAD_H
#define LOADTHREAD_H

#include <QObject>
#include <QtCore>
#include <sstream>

namespace Ui {
class LoadThread;
}

class LoadThread : public QThread {
    Q_OBJECT
    protected:
        std::ostringstream    * flux;
        unsigned long long      iterations;

    signals:
        void computingProgressed(double);

    public:
        LoadThread(std::ostringstream * pflux, unsigned long long piterations);
        virtual ~LoadThread();

        void run();
};

#endif // LOADTHREAD_H
