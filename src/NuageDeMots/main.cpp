#include "FileReader.h"
#include "Hashtable.h"

using namespace std;

int main()
{
    FileReader fr;
//    fr.read("verne.book");

    Hashtable* ht = new Hashtable(4096);

    delete ht;
    return 0;
}

