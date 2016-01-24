#ifndef THREADEXTRACT_H
#define THREADEXTRACT_H

#include <iostream>
#include <string>

#include <QtCore>

namespace Ui {
    class ThreadExtract;
}

class ThreadExtract : public QThread {
    private:
        Ui::MainWindow * ui;
        std::string mainFile_;
        IFileReader * fr_; /// The file reader to process the text
        unsigned int maxPrint_; /// How many words printed in result

    public:
        ThreadExtract(std::string, std::string, std::string, unsigned int = 20); /// Constructor
        virtual ~ThreadExtract();   /// Destructor

        void run();
};

#endif // THREADEXTRACT_H
