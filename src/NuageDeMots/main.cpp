#include <iostream>
#include <string>

#include "FileReader.h"
#include "BinarySearchTree.h"
#include "WordsGenerator.h"

using namespace std;

/** \brief Test if the file exists or not

 * \param The full path or name of the file to test
 *
 * \return True if the file exists, else false
*/
bool is_readable(const string &file) {
  ifstream fichier(file.c_str());
  return !fichier.fail();
}

int main() {
    std::string buff1, buff2, buff3;
    int choice = 0, nb_letters;

    FileReader *f, *fl;
    WordsGenerator* wg;

    cout << "Lecture" << endl;
    FileReader fr;
    fr.read("hill.bk");


    setlocale(LC_ALL, "");

    while(choice != 9) {
        cout << "-------------------- Nuage de Mots --------------------\n" << endl;
        cout << "Selectionner une action :\n\t1 : Nuage de mots a partir de fichier texte\n\t2 : Generation de mots aleatoires\n\t9 : Quitter le programme\n\nChoix ? (1 / 2 / 9) : ";
        cin >> choice; fflush(stdin); // fflush pour pas que le \n soit pris dans le suivant cin

        if(choice == 1) { // Extraction du nuage
            cout << "----- Extraction de Nuage de Mots -----\n";
            cout << "Fichier de mots a ignorer (laisser vide pour fichier par defaut) : \n";
            getline(cin, buff1);
            cout << "Fichier de sepatateurs (laisser vide pour fichier par defaut) : \n";
            getline(cin, buff2);
            cout << "Fichier a traiter (laisser vide pour fichier par defaut) : \n";
            getline(cin, buff3);

            // Allocation du FileReader
            if((buff1.size() != 0 && buff2.size() != 0) && (is_readable(buff1) && is_readable(buff2))) {
                // On a tout eu et les fichiers existent
                cout << "Utilisation de 2 fichiers de configuration personnels" << endl;
                f = new FileReader(buff1, buff2);
            } else if ((buff1.size() == 0 && buff2.size() != 0) && (is_readable(buff2))) {
                // Pas de fichier de mots et l'autre fichier existe
                cout << "Utilisation de sepatateurs personnels" << endl;
                f = new FileReader("ignore.conf", buff2);
            } else if ((buff2.size() == 0 && buff1.size() != 0) && (is_readable(buff1))) {
                // Pas de separateurs
                cout << "Utilisation de la liste personnelle de mots a ignorer" << endl;
                f = new FileReader(buff1, "filereader.conf");
            } else {
                // On a rien
                cout << "\n** Utilisation des fichiers par defaut" << endl;
                f = new FileReader();
            }

            system("pause"); // Attente de confirmation

            // Ouverture du fichier a traiter
            if(buff3 != "\n" && is_readable(buff3)) {
                // Le fichier a traiter existe
                f->read(buff3.c_str());
            } else {
                // Le fichier a traiter n'existe pas
                cout << "\n** Utilisation du fichier a traiter par defaut" << endl;
                f->read("hill.bk");
            }

            // Affichage de la liste de mots triee par occurences
            f->printStudyTable();

            // Liberation de memoire
            delete f;
        } else if (choice == 2) { // Generation de mots
            cout << "----- Creation de mots aleatoires -----" << endl;

            fl = new FileReader("nawak.conf", "nawak.conf");
            fl->read("dico.bk");
            wg = new WordsGenerator("alphabet.az"); // Generation aleatoire de mots


            for(unsigned long i = 0 ; i < 1000000 ; ++i) {
                string str = wg->rand();
                if(fl->contains(str)) {
                    cout << str << "\t" << i+1 << endl;
                }
            }

            // Liberation de memoire
            delete fl;
            delete wg;
        } else if (choice != 9) {
            cout << "Choix incorrect !" << endl;
            choice = -1;
        }
    }

    return 0;
}

