#ifndef HASHELEMENT_H
#define HASHELEMENT_H

#include <string>

class Hashelement {

    protected:
        int key_;            // Hashcode of the element
        std::string word_;   // Value of the element

    public:
        Hashelement();
        Hashelement(std::string);
        Hashelement(int, std::string);
        virtual ~Hashelement();

        int getKey() const;
        std::string getValue() const;
        const std::string toString() const;

        void setKey(int);

};

#endif // HASHELEMENT_H
