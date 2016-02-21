// Constructor using default file
template<template<typename = std::string> class C>
FileReader<C>::FileReader(std::string p_fileignore, std::string p_fileconf) : m_wordCount(0), m_open(false), m_isPdf(false) {
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
std::streambuf * FileReader<C>::open(std::string p_filename) {
    std::istream * retour = NULL;
    m_open = false;
    m_isPdf = false;

    if(p_filename.substr(p_filename.length()-4) == ".pdf") {
        PDFReader p(p_filename);
        for(auto str : p.getLines()) m_stream << str << std::endl;
        retour = &m_stream;
        m_open = true;
        m_isPdf = true;
    } else {
        if(m_file.is_open()) {
            m_file.close();
        }
        m_file.open(p_filename.c_str(), std::ifstream::in);
        if(m_file.is_open()) {
            m_open = true;
            retour = &m_file;
        } else {
            std::cerr << "FileReader error: cannot open this file " << p_filename << std::endl;
        }
    }

    return retour->rdbuf();
}

template<template<typename = std::string> class C>
void FileReader<C>::read(std::string p_filename) {
    std::string buffer;
    std::istream flux(this->open(p_filename));
    std::ofstream out("out.xxx");
    if(m_open) {
        while(getline(flux, buffer)) {
            out << buffer << std::endl;
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
    } else {
        std::cerr << "FileReader error: cannot read the file " << p_filename << std::endl;
    }
}

template<template<typename = std::string> class C>
unsigned FileReader<C>::minuscule(unsigned c) {
    if(c=='É')
        return 'é';
    else
        return tolower(c);
}

template<template<typename = std::string> class C>
void FileReader<C>::process(std::string p_stringToProcess) {
    for(unsigned i = 0 ; i < p_stringToProcess.size() ; i++) {
        p_stringToProcess[i] = minuscule(p_stringToProcess[i]);
    }
    if(p_stringToProcess.length() > 2 && !m_ignoredWords.contains(p_stringToProcess)) {
        m_studiedWords.add(p_stringToProcess);
    }
    m_wordCount++;
}

template<template<typename = std::string> class C>
bool FileReader<C>::contains(std::string p_toFind) const {
    return m_studiedWords.contains(p_toFind);
}

template<template<typename = std::string> class C>
std::vector<std::string> FileReader<C>::printStudyTable() {
    m_studiedWords.deletePlurals();
    std::vector<std::string> retour = m_studiedWords.sort();
    std::cout << "Nombre de mots : " << m_wordCount << std::endl;
    return retour;
}

template<template<typename = std::string> class C>
bool FileReader<C>::isSeparator(const char & p_char) {
    unsigned int i = 0;
    while(i < m_separator.size() && p_char!=m_separator[i++]);
    return m_separator[i-1]==p_char;
}

