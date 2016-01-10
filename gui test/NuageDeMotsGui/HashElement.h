#ifndef HASHELEMENT_H
#define HASHELEMENT_H

#include <string>
#include "Countable.h"

template <typename T>
class HashElement : public Countable {

    protected:
        T                   value_;   // Value of the element
        unsigned long int   key_; // Key of the element

    public:
        HashElement();
        HashElement(T);
        HashElement(T, unsigned long int);
        virtual ~HashElement();

        unsigned long int getKey() const;
        T getValue() const;
        const std::string & toString() const;

        void setKey(unsigned long int);
};

#include "HashElement.tpp"

#endif // HASHELEMENT_H
