#include "Hashelement.h"

// Default constructor
Hashelement::Hashelement() : key_(0), word_("")
    {}

// Constructor with parameters
Hashelement::Hashelement(int key, std::string word) : key_(key), word_(word)
    {}

int Hashelement::getKey() const {
    return key_;
}

std::string Hashelement::getValue() const {
    return word_;
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
