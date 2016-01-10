#include "Countable.h"

Countable::Countable(const int & p_number) {
    setNumber(p_number);
}

Countable::~Countable() {
    //dtor
}

Countable::Countable(const Countable & p_toCopy) {
    if (this != &p_toCopy) {
        this->setNumber(p_toCopy.number());
    }
}

Countable& Countable::operator=(const Countable& p_toCopy) {
    if (this != &p_toCopy) {
        this->setNumber(p_toCopy.number());
    }
    return *this;
}

int Countable::number() const {
    return m_number;
}

void Countable::setNumber(const int & p_number) {
    m_number = p_number;
}

Countable & Countable::operator++() {
    m_number++;
    return *this;
}

Countable Countable::operator++(int) {
    Countable inc = ++(*this);
    return inc;
}

Countable & Countable::operator--() {
    m_number--;
    return *this;
}

Countable Countable::operator--(int) {
    Countable inc = --(*this);
    return inc;
}
