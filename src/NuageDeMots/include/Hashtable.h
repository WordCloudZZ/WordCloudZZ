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
        unsigned int                              size_;
        std::vector<HashElement<T> >            * table_;
        std::forward_list<HashElement<T> >        sorted_;

        unsigned long int hashCode(T) const;
        unsigned long int addElement(HashElement<T>*);
        HashElement<T> * search(const T &) const;
        bool increase(HashElement<T> *, long);
        bool increase(const T &, long);
        bool erase(const T & value);

    public:
        Hashtable(unsigned int = 1024);
        virtual ~Hashtable();

        bool add(const T &);
        unsigned int size() const;
        bool contains(const T &) const;
        void printAll() const;

        std::string toString() const;
        std::string sort();
        void deletePlurals();
};

#include "Hashtable.tpp"

#endif // HASHTABLE_H
