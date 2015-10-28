#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <iostream>
#include <forward_list>
#include <iterator>

#include "HashElement.h"

template <typename T>
class Hashtable {

    protected:
        unsigned int                    size_;
        std::vector<HashElement<T> >  * table_;

        unsigned long int hashCode(T) const;
        unsigned long int addElement(HashElement<T>*);

    public:
        Hashtable(unsigned int);
        virtual ~Hashtable();

        HashElement<T> * at(int) const;
        unsigned long int addElement(T);

        unsigned int size() const;
        bool contains(const T &) const;
        void printAll() const;

        std::string toString() const;
        std::string sort() const;
};

#include "Hashtable.tpp"

#endif // HASHTABLE_H
