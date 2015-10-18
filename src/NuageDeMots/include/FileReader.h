#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>

class FileReader {
    protected:
        std::ifstream           m_file;
        std::string             m_separator;

    public:
        FileReader();
        virtual ~FileReader();

        void read(std::string);
        void process(std::string);

    private:
        bool isSeparator(const char &);
};

#endif // FILEREADER_H
