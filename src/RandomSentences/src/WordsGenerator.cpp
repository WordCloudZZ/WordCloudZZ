#include "WordsGenerator.h"

WordsGenerator::WordsGenerator(std::string p_seed, const char p_filename[]) :
    m_seed(p_seed.begin(),p_seed.end()), m_random(m_seed) {
    std::ifstream       file; // Any file used

    // Loading alphabet from given file in a string
    file.open(p_filename, std::ifstream::in);
    if(file.is_open()) {
        getline(file, m_alphabet);
        file.close();
    } else {
    	std::cout << "Error: can't open this file." << std::endl;
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

std::string WordsGenerator::generateWord(unsigned p_size) {
    std::string retour;
    for(unsigned i = 0 ; i < p_size ; ++i) {
        retour.push_back(m_alphabet[this->rand(0,m_alphabet.length()-1)]);
    }
    return retour;
}

long long WordsGenerator::rand(long long int a, long long int b) {
    return (m_random()/(double)m_random.max())*(b-a+1)+a;
}

unsigned long long WordsGenerator::expectWord(std::string p_str) {
    unsigned                courrant    = 0;
    unsigned long long      tirages     = 0;
    char                    lettre      = '\0';

    while(courrant < p_str.length()) {
        lettre = m_alphabet[this->rand(0,m_alphabet.length()-1)];
        //courrant = (p_str[courrant] == lettre) ? courrant++ : 0;
        if(p_str[courrant] == lettre) {
            //std::cout << lettre;
            courrant++;
        } else {
            //if(courrant > 0)
            //    std::cout << std::endl;
            courrant = 0;
        }
        tirages++;
    }

    std::cout << std::endl << "Number of drawings: " << tirages << std::endl;

    return tirages;
}

Stats WordsGenerator::studySentence(std::string p_str, unsigned p_iter) {
    Stats results;
    clock_t start, end;
    std::vector<double> tirages(p_iter);
    std::cout << "////////////////////////////////////////////////////////////////" << std::endl << std::endl;
    std::cout << "\tSTARTING OF STUDY OF:" << std::endl;
    std::cout << "\t\t" << p_str << std::endl << std::endl;
    std::cout << "////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    start = clock();    // temps de debut

    for(unsigned i = 0 ; i < p_iter ; ++i) {        // calcul des echantillons
        std::cout << "Round " << i+1 << std::endl;
        tirages.push_back(this->expectWord(p_str.c_str()));
        std::cout << "----------------------------------------------------------------" << std::endl;
    }

    end = clock();      // temps de fin

    results.setAverage(tirages);
    results.setVariance(tirages, results.average);
    results.time= (end-start)/1000.0;

    std::cout << "////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "\tRESULTS:" << std::endl;
    std::cout << "\t +\tAverage:\t" << (unsigned long long)results.average << std::endl;
    std::cout << "\t +\tVariance:\t" << (unsigned long long)results.variance << std::endl;
    std::cout << "\t +\tConfidence int:\t[ " << (unsigned long long)(results.average-results.radius) << " ; " << (unsigned long long)(results.average+results.radius) << " ]" << std::endl;
    std::cout << "\t +\tExecution time:\t" << results.time << " s" << std::endl;
    std::cout << "////////////////////////////////////////////////////////////////" << std::endl;

    return results;
}

