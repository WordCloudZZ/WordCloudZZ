#include "Hashtable.h"

// Default constructor
Hashtable::Hashtable() : size_(256) {
    table_ = new Hashelement[size_];
}

// Constructor with parameters
Hashtable::Hashtable(int table_size) : size_(table_size) {
    table_ = new Hashelement[size_];
}

// Return element at a certain position
Hashelement Hashtable::getAt(int place) const {
    return table_[place];
}

// Create a hash code, using a string
int Hashtable::hashCode(std::string str) const {
    // Using dj2b hash method
    unsigned long code = 5381;

    for(unsigned int i = 0; i < str.length(); i++) {
        code = ((code << 5) + code) + str[i];
    }

    return (code%size_); // To make sure we are in range
}

// Add an element in the right place
int Hashtable::addElement(Hashelement to_add) {
    int hash_code = hashCode(to_add.getValue()); // Get hash code

    table_[hash_code] = to_add; // TODO : collisions

    to_add.setKey(hash_code); // Change the key for the element

        std::cout << "Ajout de l'element " << to_add.getValue() << " a la place " << to_add.getKey() << std::endl;

    return to_add.getKey(); // In case we need it
}

std::string Hashtable::toString() const {
    std::string out = "-- Table --\n";
    out += "Taille max : " + size_;
    return out;
}

// Destructor
Hashtable::~Hashtable() {
    if(table_) {
        delete [] table_;
    }
}