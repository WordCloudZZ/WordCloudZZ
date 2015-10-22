#include "FileReader.h"
#include "Hashtable.h"

using namespace std;

int main()
{
    FileReader fr;
    fr.read("bigfile.txt"); // Fichier de test 100k lines
    fr.printStudyTable();


    /// Test de la table seule
    //Hashtable<string> * ht = new Hashtable<string>(4096);
    //delete ht;
    return 0;
}

