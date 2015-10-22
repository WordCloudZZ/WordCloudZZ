#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

#include "Hashelement.h"

template <typename T>
class Hashtable {

    protected:
        unsigned int        size_;
        HashElement<T>   ** table_;

        unsigned long int hashCode(T) const;
        void fillNull();

    public:
        Hashtable();
        Hashtable(unsigned int);
        virtual ~Hashtable();

        HashElement<T> * getAt(int) const;
        unsigned long int addElement(HashElement<T>*);
        unsigned long int addElement(T);

        unsigned int size() const;
        bool contains(const T &) const;

        std::string toString() const;

    private:
};

#include "Hashtable.tpp"

#endif // HASHTABLE_H
