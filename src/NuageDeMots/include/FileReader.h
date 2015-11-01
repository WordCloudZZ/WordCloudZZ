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
        FileReader(std::string = "ignore.conf", std::string = "filereader.conf");
        virtual ~FileReader();

        void read(std::string);
        bool contains(std::string) const;
        void process(std::string);

        void printStudyTable() const;

    private:
        bool isSeparator(const char &);
};

#endif // FILEREADER_H
