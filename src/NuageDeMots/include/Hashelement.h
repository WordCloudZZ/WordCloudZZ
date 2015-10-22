#ifndef HASHELEMENT_H
#define HASHELEMENT_H

#include <string>

template <typename T>
class HashElement {

    protected:
        std::string         value_;   // Value of the element
        unsigned long int   key_, // Key of the element
                            number_collisions_; // Number of collisions

    public:
        HashElement();
        HashElement(T);
        HashElement(T, unsigned long int);
        virtual ~HashElement();

        unsigned long int getKey() const;
        T getValue() const;
        const std::string & toString() const;

        void setKey(unsigned long int);
        HashElement<T> & operator++();
        HashElement<T> operator++(int);
};

#include "HashElement.tpp"

#endif // HASHELEMENT_H
