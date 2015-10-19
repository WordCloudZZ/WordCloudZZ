#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

#include "Hashelement.h"

class Hashtable {

    protected:
        Hashelement* table_;
        int size_;

    public:
        Hashtable();
        Hashtable(int);
        virtual ~Hashtable();

        Hashelement getAt(int) const;
        int hashCode(std::string) const;
        int addElement(Hashelement);

        std::string toString() const;

    private:
};

#endif // HASHTABLE_H
