// Default constructor
template <typename T>
HashElement<T>::HashElement() : value_(""), key_(0) {

}

// Constructor with parameters
template <typename T>
HashElement<T>::HashElement(T value, unsigned long int key) : value_(value), key_(key) {

}

template <typename T>
HashElement<T>::HashElement(T value) : value_(value), key_(0) {

}

template <typename T>
unsigned long int HashElement<T>::getKey() const {
    return key_;
}

template <typename T>
T HashElement<T>::getValue() const {
    return value_;
}

// Change the key for the element
template <typename T>
void HashElement<T>::setKey(unsigned long int key) {
    key_ = key;
}

template <typename T>
const std::string & HashElement<T>::toString() const {
    std::string out = "Cle : " + key_;
    out += " - Valeur : " + value_;
    return out;
}

// Destructor
template <typename T>
HashElement<T>::~HashElement() {
    // Nothing to do
}
