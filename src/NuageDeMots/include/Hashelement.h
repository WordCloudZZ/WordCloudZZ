#ifndef HASHELEMENT_H
#define HASHELEMENT_H

#include <string>

class Hashelement {

    protected:
        std::string word_;   // Value of the element
        unsigned long int key_; // Hashcode of the element

    public:
        Hashelement();
        Hashelement(std::string);
        Hashelement(std::string, unsigned long int);
        virtual ~Hashelement();

        unsigned long int getKey() const;
        std::string getValue() const;
        const std::string toString() const;

        void setKey(unsigned long int);

};

#endif // HASHELEMENT_H
