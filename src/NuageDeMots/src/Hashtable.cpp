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


// Destructor
Hashtable::~Hashtable() {
    if(table_) {
        delete [] table_;
    }
}
