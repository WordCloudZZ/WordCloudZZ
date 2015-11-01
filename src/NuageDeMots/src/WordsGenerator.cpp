#include "WordsGenerator.h"

WordsGenerator::WordsGenerator(const char p_filename[] = "alphabet.az") {
    std::ifstream   file; // Any file used
    // Loading alphabet from given file in a string
    file.open(p_filename, std::ifstream::in);
    if(file.is_open()) {
        getline(file, m_alphabet);
        file.close();
    }
}

WordsGenerator::WordsGenerator(const WordsGenerator & p_toCopy) {
    m_alphabet = p_toCopy.m_alphabet;
    m_random = p_toCopy.m_random;
}

WordsGenerator::~WordsGenerator() {
    //dtor
}

WordsGenerator & WordsGenerator::operator=(WordsGenerator & p_toCopy) {
    m_alphabet = p_toCopy.m_alphabet;
    m_random = p_toCopy.m_random;
    return (*this);
}

std::string WordsGenerator::rand(unsigned p_size) {
    std::string retour;
    for(unsigned i = 0 ; i < p_size ; ++i) {
        retour.push_back(m_alphabet[m_random.rand(0,m_alphabet.length()-1)]);
    }
    return retour;
}
