#include "FileReader.h"

using namespace std;

int main()
{
    FileReader fr;

    setlocale(LC_ALL, "");
    //fr.read("bigfile.txt"); // Fichier de test 100k lines
  //  fr.printStudyTable();


    /// Test de la table seule
    //Hashtable<string> * ht = new Hashtable<string>(4096);
    //delete ht;

  //  fr.read("20000_lieues.book");
    fr.read("hill.book");

    return 0;
}

