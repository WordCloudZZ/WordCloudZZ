#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "Hashtable.h"

class FileReader {
    protected:
        std::ifstream                   m_file; // Any file used
        std::string                     m_separator; // Contains the list of separators
        Hashtable<std::string>          m_ignoredWords; // Storing words we have to ignore
        Hashtable<std::string>          m_studiedWords; // Storing words we have to study

    public:
        FileReader();
        FileReader(std::string);
        virtual ~FileReader();

        void read(std::string);
        void process(std::string);

    private:
        bool isSeparator(const char &);
};

#endif // FILEREADER_H
