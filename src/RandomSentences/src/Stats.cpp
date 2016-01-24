#include "Stats.h"

Stats::Stats() : m_average(0), m_variance(0), m_radius(0), m_time(0), m_number(0) {

}

Stats::~Stats() {
    //dtor
}

void Stats::setAverage(const std::vector<double> & p_tab) {
    /* -------------------------------------------------------------------- */
    /* setAverage  Estime l'esperance                                       */
    /*                                                                      */
    /* En entree: p_tab : vector<double>                                    */
    /* -------------------------------------------------------------------- */
    double esperance = 0.0;
    for(unsigned int i = 0 ; i < p_tab.size() ; ++i) {
        esperance += p_tab.at(i);
    }
    esperance = esperance / (double)(p_tab.size());
    m_average = esperance;
    m_number = p_tab.size();
}

void Stats::setVariance(const std::vector<double> & p_tab, double p_esperance) {
    /* -------------------------------------------------------------------- */
    /* setVariance  Estime la variance                                      */
    /*                                                                      */
    /* En entree: p_tab : vector<double> ; p_esperance : double             */
    /* -------------------------------------------------------------------- */
    double lvariance = 0.0;
    for(unsigned int i = 0 ; i < p_tab.size() ; ++i) {
        lvariance = lvariance + ((p_esperance - p_tab.at(i))*(p_esperance - p_tab.at(i)));
    }
    lvariance = lvariance / (double)p_tab.size();
    m_variance = lvariance;
    m_number = p_tab.size();
}

void Stats::setRadius(double p_variance, unsigned long long p_experiences) {
    /* -------------------------------------------------------------------- */
    /* setRadius  Estime le rayon de l'intervale de confiance               */
    /*                                                                      */
    /* En entree: p_variance : double ; p_experiences unsigned long long    */
    /* -------------------------------------------------------------------- */
    Student st;
    double lradius = st.getQuantile(p_experiences)*sqrt(p_variance/p_experiences);
    if(p_variance != m_variance)
        std::cerr << "Stats : attention variance locale != variance en parametre." << std::endl;
    m_radius = lradius;
    m_number = p_experiences;
}

void Stats::setTime(double p_time) {
    /* -------------------------------------------------------------------- */
    /* setTime  Estime le temps d'execution                                 */
    /*                                                                      */
    /* En entree: p_time : double                                           */
    /* -------------------------------------------------------------------- */
    m_time = p_time;
}

void Stats::setNumber(unsigned long long p_number) {
    /* -------------------------------------------------------------------- */
    /* setNumber  Met a jour le nombre d'echantillon                        */
    /*                                                                      */
    /* En entree: p_number : unsigned long long                             */
    /* -------------------------------------------------------------------- */
    m_number = p_number;
}
