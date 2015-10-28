#include "FileReader.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    FileReader fr;

    //fr.read("bigfile.txt"); // Fichier de test 100k lines
  //  fr.printStudyTable();


    /// Test de la table seule
    //Hashtable<string> * ht = new Hashtable<string>(4096);
    //delete ht;

  //  fr.read("20000_lieues.book");
    fr.read("hill.bk");

    return 0;
}

