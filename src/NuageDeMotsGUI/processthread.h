#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <string>
#include <vector>

#include <QtCore>
#include <QObject>

#include "FileReader.h"

namespace Ui {
    class ProcessThread;
}

class ProcessThread : public QThread {
    Q_OBJECT

    protected:
        typedef std::vector<std::string> stringVec;
        std::string principal;
        std::string separator;
        std::string ignore;
        IFileReader * fr;

    public:
        ProcessThread(std::string, std::string, std::string);
        ~ProcessThread();

        void run();

    signals:
        void processEnd(stringVec);
};

#endif // PROCESSTHREAD_H
