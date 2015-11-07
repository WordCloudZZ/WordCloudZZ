#ifndef WORDSGENERATOR_H
#define WORDSGENERATOR_H

#include <string>
#include <fstream>
#include <iostream>
#include "Mersenne.h"

class WordsGenerator {
    protected:
        Mersenne        m_random;
        std::string     m_alphabet;

    public:
        /** Default constructor */
        WordsGenerator(const char [] = "alphabet.az");
        /** Copy constructor */
        WordsGenerator(const WordsGenerator &);
        /** Default destructor */
        virtual ~WordsGenerator();
        /** Assignement operation */
        WordsGenerator & operator=(WordsGenerator &);

        std::string rand(unsigned = 5);
        unsigned long long expectWord(std::string = "hazard");
};

#endif // WORDSGENERATOR_H
