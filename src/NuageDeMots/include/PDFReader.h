#ifndef PDFREADER_H
#define PDFREADER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class PDFReader {
    protected:
        FILE                          * m_pdf;
        std::string                     m_filename;
        std::vector<std::string>        m_lines;
        bool                            m_open;
        
    public:
        PDFReader(std::string filename = "");
        virtual ~PDFReader();
        
        bool open(std::string filename);
        bool close();
        bool isOpen() const;
        std::vector<std::string> getLines() const;
        
    private:
        bool process();
        void subProcess(char* output, size_t len);
};

#endif
