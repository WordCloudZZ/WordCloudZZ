#ifndef WORDSGENERATOR_H
#define WORDSGENERATOR_H

#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>

class Stats {
    public:
        double average, variance, radius, time;

        Stats() : average(0), variance(0), radius(0), time(0) {

        }

        void setAverage(const std::vector<double> & p_tab) {
        /* -------------------------------------------------------------------- */
        /* getEsperance  Estime l'esperance                                     */
        /*                                                                      */
        /* En entree: p_tab : vector<double>                                    */
        /*                                                                      */
        /* En sortie: double                                                    */
        /* -------------------------------------------------------------------- */
            double esperance = 0.0;
            for(unsigned int i = 0 ; i < p_tab.size() ; ++i) {
                esperance += p_tab.at(i);
            }
            esperance = esperance / (double)(p_tab.size());
            average = esperance;
        }

        void setVariance(const std::vector<double> & p_tab, double p_esperance) {
            /* -------------------------------------------------------------------- */
            /* getVariance  Estime la variance                                      */
            /*                                                                      */
            /* En entree: p_tab : vector<double> ; p_esperance : double             */
            /*                                                                      */
            /* En sortie: double                                                    */
            /* -------------------------------------------------------------------- */
            double lvariance = 0.0;
            for(unsigned int i = 0 ; i < p_tab.size() ; ++i) {
                lvariance = lvariance + ((p_esperance - p_tab.at(i))*(p_esperance - p_tab.at(i)));
            }
            lvariance = lvariance / (double)p_tab.size();
            variance = lvariance;
        }
};

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
        unsigned long long expectWord(std::string = "hazard");
        Stats studySentence(std::string p_str, unsigned p_iter);
};

#endif // WORDSGENERATOR_H
