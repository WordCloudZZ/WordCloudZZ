// Default constructor
template <typename T>
Hashtable<T>::Hashtable() : size_(256) {
    table_ = new HashElement<T>*[size_];
    fillNull();
}

// Constructor with parameters
template <typename T>
Hashtable<T>::Hashtable(unsigned int table_size) : size_(table_size) {
    table_ = new HashElement<T>*[size_];
    fillNull();
}

// Destructor
template <typename T>
Hashtable<T>::~Hashtable() {
    if(table_) {
        for(unsigned int i = 0; i < size_ ; i++) {
            if(table_[i] != 0) {
                delete (table_[i]);
            }
        }
        delete [] table_;
    }
}

// Fill the table with null pointers
template <typename T>
void Hashtable<T>::fillNull() {
    for(unsigned int i = 0; i < size_; i++) {
        table_[i] = 0; // Set everything to NULL
    }
}

// Return element at a certain position
template <typename T>
HashElement<T>* Hashtable<T>::getAt(int place) const {
    return table_[place];
}

template <typename T>
unsigned int Hashtable<T>::size() const {
    return size_;
}

// Create a hash code, using a string                       /// ONLY for strings
template <typename T>                                       /// TODO: Make a general method
unsigned long int Hashtable<T>::hashCode(T key) const {
    // Using dj2b hash method
    unsigned long code = 5381;

    for(unsigned int i = 0; i < key.length(); i++) {
        code = ((code << 5) + code) + key[i];
    }

    return (code%size_); // To make sure we are in range
}

template <typename T>
unsigned long int Hashtable<T>::addElement(T value) {
    unsigned long int hash_code = hashCode(value); // Get hash code
    HashElement<T> * to_add = new HashElement<T>(value, hash_code);

    table_[hash_code] = to_add; // TODO : collision

std::cout << "Ajout de l'element " << to_add->getValue() << " a la place " << to_add->getKey() << std::endl;

    return to_add->getKey(); // In case we need it
}

// Add an element in the right place
template <typename T>
unsigned long int Hashtable<T>::addElement(HashElement<T> * to_add) {
    unsigned long int hash_code = hashCode(to_add->getValue()); // Get hash code

    table_[hash_code] = to_add; // TODO : collisions

    to_add->setKey(hash_code); // Change the key for the element

std::cout << "Ajout de l'element " << to_add->getValue() << " a la place " << to_add->getKey() << std::endl;

    return to_add->getKey(); // In case we need it
}

template <typename T>
std::string Hashtable<T>::toString() const {
    std::string out;
    out += "-- Table --\n";
    out += "Taille max : " + this->size(); // TODO fix the printing of the size ...
    return out;
}

