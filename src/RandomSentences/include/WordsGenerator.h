#ifndef WORDSGENERATOR_H
#define WORDSGENERATOR_H

#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>

#include "Stats.h"

class WordsGenerator {
    protected:
        std::seed_seq   m_seed;
        std::mt19937    m_random;
        std::string     m_alphabet;

    public:
        /** Default constructor */
        WordsGenerator(std::string = "Le hasard ne fait des phrases.", const char [] = "alphabet.az");
        /** Copy constructor */
        WordsGenerator(const WordsGenerator &);
        /** Default destructor */
        virtual ~WordsGenerator();
        /** Assignement operation */
        WordsGenerator & operator=(WordsGenerator &);

        std::string generateWord(unsigned p_size = 5);
        long long rand(long long int a, long long int b);
        unsigned long long expectWord(std::string = "hazard", std::ostream& = std::cout);
        Stats studySentence(std::string p_str, unsigned p_iter, std::ostream& = std::cout);
};

#endif // WORDSGENERATOR_H
