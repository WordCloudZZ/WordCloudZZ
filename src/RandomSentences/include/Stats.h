#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <vector>
#include <cmath>

#include "Student.h"

class Stats {
    protected:
        double                  m_average,
                                m_variance,
                                m_radius,
                                m_time;
        unsigned long long      m_number;

    public:
        Stats();
        virtual ~Stats();

        void setAverage(const std::vector<double> & p_tab);
        void setVariance(const std::vector<double> & p_tab, double p_esperance);
        void setRadius(double p_variance, unsigned long long p_experiences);
        void setTime(double);
        void setNumber(unsigned long long);

        double average() const  { return m_average; }
        double variance() const { return m_variance; }
        double radius() const   { return m_radius; }
        double time() const     { return m_time; }
        unsigned long long number() const   { return m_number; }
};

#endif // STATS_H
