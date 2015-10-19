#include "FileReader.h"
#include "Hashtable.h"

using namespace std;

int main()
{
//    FileReader fr;
//    fr.read("verne.book");

    Hashtable* ht = new Hashtable(1024);
    std::string tmp;

    for(unsigned int i = 0; i<512; i++) {
        tmp = (char)i + 48 % 122;
        ht->addElement(Hashelement(tmp) );
    }

    std::cout << ht->toString();

    delete ht;
    return 0;
}
