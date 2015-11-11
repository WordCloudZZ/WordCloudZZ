#include "WordsGenerator.h"

WordsGenerator::WordsGenerator(const char p_filename[]) {
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

unsigned long long WordsGenerator::expectWord(std::string p_str) {
    unsigned                courrant    = 0;
    unsigned long long      tirages     = 0;
    char                    lettre      = '\0';

    while(courrant < p_str.length()) {
        lettre = m_alphabet[m_random.rand(0,m_alphabet.length()-1)];
        //courrant = (p_str[courrant] == lettre) ? courrant++ : 0;
        if(p_str[courrant] == lettre) {
          //  std::cout << lettre;
            courrant++;
        } else {
        /*    if(courrant > 0)
                std::cout << std::endl;*/
            courrant = 0;
        }
        tirages++;
    }

    std::cout << std::endl << "Nombre de tirages : " << tirages << std::endl;

    return tirages;
}

