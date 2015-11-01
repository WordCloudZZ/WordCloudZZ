#ifndef WORDSGENERATOR_H
#define WORDSGENERATOR_H

#include <string>
#include <fstream>
#include "Mersenne.h"

class WordsGenerator {
    protected:
        Mersenne        m_random;
        std::string     m_alphabet;

    public:
        /** Default constructor */
        WordsGenerator(const char []);
        /** Copy constructor */
        WordsGenerator(const WordsGenerator &);
        /** Default destructor */
        virtual ~WordsGenerator();
        /** Assignement operation */
        WordsGenerator & operator=(WordsGenerator &);

        std::string rand(unsigned = 5);
};

#endif // WORDSGENERATOR_H
