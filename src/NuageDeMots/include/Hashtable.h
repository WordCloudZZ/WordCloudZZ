#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

#include "Hashelement.h"

class Hashtable {

    protected:
        unsigned int size_;
        Hashelement* table_;

    public:
        Hashtable();
        Hashtable(unsigned int);
        virtual ~Hashtable();

        Hashelement getAt(int) const;
        unsigned long int hashCode(std::string) const;
        unsigned long int addElement(Hashelement);
        unsigned long int addElement(std::string);

        unsigned int getSize() const;

        std::string toString() const;

    private:
};

#endif // HASHTABLE_H
