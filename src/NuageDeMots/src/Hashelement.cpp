#include "Hashelement.h"

// Default constructor
Hashelement::Hashelement() : word_(""), key_(0)
    {}

// Constructor with parameters
Hashelement::Hashelement(std::string word, unsigned long int key) : word_(word), key_(key)
    {}

Hashelement::Hashelement(std::string word) : word_(word), key_(0)
    {}

unsigned long int Hashelement::getKey() const {
    return key_;
}

std::string Hashelement::getValue() const {
    return word_;
}

// Change the key for the element
void Hashelement::setKey(unsigned long int key) {
    key_ = key;
}

const std::string Hashelement::toString() const {
    std::string out = "Cle : " + key_;
    out += " - Valeur : " + word_;
    return out;
}

// Destructor
Hashelement::~Hashelement() {
    // Nothing to do
}
