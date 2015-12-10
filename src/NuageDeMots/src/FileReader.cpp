#include "FileReader.h"

// Constructor using default file
FileReader::FileReader(std::string p_fileignore, std::string p_fileconf) {
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

FileReader::~FileReader() {
    if(m_file.is_open()) {
        m_file.close();
    }
}

void FileReader::read(std::string p_filename) {
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
        //m_studiedWords.sort();
    } //if
}

void FileReader::process(std::string p_stringToProcess) {
    std::transform(p_stringToProcess.begin(), p_stringToProcess.end(), p_stringToProcess.begin(), tolower);
    if(!m_ignoredWords.contains(p_stringToProcess)) {
        m_studiedWords.add(p_stringToProcess);
    }
}

bool FileReader::contains(std::string p_toFind) const {
    return m_studiedWords.contains(p_toFind);
}

void FileReader::printStudyTable() const {
    m_studiedWords.sort();
}

bool FileReader::isSeparator(const char & p_char) {
    unsigned int i = 0;
    while(i < m_separator.size() && p_char!=m_separator[i++]);
    return m_separator[i-1]==p_char;
}

