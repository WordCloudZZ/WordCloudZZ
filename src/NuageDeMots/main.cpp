#include "FileReader.h"
#include "Hashtable.h"

using namespace std;

int main()
{
    FileReader fr;
    fr.read("verne.book");

    Hashtable<string> * ht = new Hashtable<string>(4096);

    delete ht;
    return 0;
}

