#include "FileReader.h"

FileReader::FileReader() {
    m_file.open("filereader.conf", std::ifstream::in);
    if(m_file.is_open()) {
        getline(m_file, m_separator);
        m_file.close();
    }
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
                if(isSeparator(buffer[cour])) {
                    if(cour!=start) {
                        this->process(buffer.substr(start, cour-start));
                    }
                    start = cour + 1;
                }
                cour++;
            }
        }
    }
}

void FileReader::process(std::string p_stringToProcess) {
    std::cout << p_stringToProcess << std::endl;
}

bool FileReader::isSeparator(const char & p_char) {
    unsigned int i = 0;
    while(i < m_separator.size() && p_char!=m_separator[i++]);
    return m_separator[i-1]==p_char;
}

