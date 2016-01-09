// Constructor using default file
template<template<typename = std::string> class C>
FileReader<C>::FileReader(std::string p_fileignore, std::string p_fileconf) : m_wordCount(0) {
    std::string buffer;

    // Loading separators from given file in a string
    m_file.open(p_fileconf, std::ifstream::in);
    if(m_file.is_open()) {
        getline(m_file, m_separator);
        m_file.close();
    }

    // Loading words to ignore from given file
    m_file.open(p_fileignore, std::ifstream::in);
    if(m_file.is_open()) {
        // Reading each line from the file
        while(getline(m_file, buffer)) {
            m_ignoredWords.add(buffer);
        } //while
    } //if

}

template<template<typename = std::string> class C>
FileReader<C>::~FileReader() {
    if(m_file.is_open()) {
        m_file.close();
    }
}

template<template<typename = std::string> class C>
void FileReader<C>::read(std::string p_filename) {
    std::string buffer;
    if(m_file.is_open()) {
        m_file.close();
    }
    m_file.open(p_filename.c_str(), std::ifstream::in);
    if(m_file.is_open()) {
        while(getline(m_file, buffer)) {
            unsigned int start=0, cour=0;
            while(cour < buffer.size()) {
                if(isSeparator(buffer[cour]) || '\n'==buffer[cour]) {
                    if(cour!=start) {
                        this->process(buffer.substr(start, cour-start));
                    }
                    start = cour + 1;
                }
                cour++;
            } //while
                    if(cour!=start) {
                        this->process(buffer.substr(start, -1));
                    }
        } //while
    } //if
}

template<template<typename = std::string> class C>
void FileReader<C>::process(std::string p_stringToProcess) {
    std::transform(p_stringToProcess.begin(), p_stringToProcess.end(), p_stringToProcess.begin(), tolower);
    if(!m_ignoredWords.contains(p_stringToProcess)) {
        m_studiedWords.add(p_stringToProcess);
    }
    m_wordCount++;
}

template<template<typename = std::string> class C>
bool FileReader<C>::contains(std::string p_toFind) const {
    return m_studiedWords.contains(p_toFind);
}

template<template<typename = std::string> class C>
void FileReader<C>::printStudyTable() {
    PDFReader p("hill.pdf");
/*
    m_studiedWords.deletePlurals();
    m_studiedWords.sort();
    std::cout << "Nombre de mots : " << m_wordCount << std::endl;
    */
}

template<template<typename = std::string> class C>
bool FileReader<C>::isSeparator(const char & p_char) {
    unsigned int i = 0;
    while(i < m_separator.size() && p_char!=m_separator[i++]);
    return m_separator[i-1]==p_char;
}

