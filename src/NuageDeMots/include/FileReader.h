#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "PDFReader.h"
#include "Hashtable.h"
#include "BinarySearchTree.h"

/// interface de FileReader
class IFileReader {
    public:
        IFileReader() {}
        virtual ~IFileReader() {}

        virtual void read(std::string) = 0;
        virtual bool contains(std::string) const = 0;
        virtual void process(std::string) = 0;
        virtual std::vector<std::string> printStudyTable() = 0;
};

template<template<typename = std::string> class C>
class FileReader : public IFileReader {
    protected:
        std::ifstream               m_file; // Any file used
        std::stringstream           m_stream;
        std::string                 m_separator; // Contains the list of separators
        unsigned long long          m_wordCount;    // nombre de mots dans le document
        C<std::string>              m_ignoredWords; // Storing words we have to ignore
        C<std::string>              m_studiedWords; // Storing words we have to study
        bool                        m_open,
                                    m_isPdf;

    public:
        FileReader(std::string = "ignore.conf", std::string = "filereader.conf");
        virtual ~FileReader();

        void read(std::string);
        std::streambuf * open(std::string);
        bool contains(std::string) const;
        void process(std::string);

        std::vector<std::string> printStudyTable();

    private:
        bool isSeparator(const char &);
};

#include "FileReader.tpp"

#endif // FILEREADER_H
