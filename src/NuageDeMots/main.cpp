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
    int choice = 0, nb_letters = 5, nb_gen = 100000;

    FileReader *f;
    WordsGenerator* wg;

    cout << "Lecture" << endl;
    FileReader fr;
    fr.read("hill.bk");


    setlocale(LC_ALL, "");

    while(choice != 9) {
        cout << "-------------------- Nuage de Mots --------------------\n" << endl;
        cout << \
"Selectionner une action :\
\n\t1 : Nuage de mots a partir de fichier texte\
\n\t2 : Generation de mots aleatoires\
\n\t9 : Quitter le programme\
\n\nChoix ? (1 / 2 / 9) : ";
        cin >> choice; fflush(stdin); // fflush pour pas que le \n soit pris dans le suivant cin

        if(choice == 1) { // Extraction du nuage
            cout << "\n----- Extraction de Nuage de Mots -----\n";
            cout << "Fichier de mots a ignorer (laisser vide pour fichier par defaut) : \n";
            getline(cin, buff1);
            cout << "\nFichier de sepatateurs (laisser vide pour fichier par defaut) : \n";
            getline(cin, buff2);
            cout << "\nFichier a traiter (laisser vide pour fichier par defaut) : \n";
            getline(cin, buff3);

            cout << "---------------" << endl; // Separation

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
                cout << "** Utilisation des fichiers de configuration par defaut" << endl;
                f = new FileReader();
            }

            if(buff3.size() == 0 || !is_readable(buff3)) {
                cout << "** Utilisation du fichier par defaut" << endl;
                buff3.clear();
                buff3="hill.bk";
            }

            cout << "\nL'analyse va débuter et les resultats seront immediatement affiches" << endl;
            system("pause"); // Attente de confirmation

            f->read(buff3.c_str());

            // Affichage de la liste de mots triee par occurences
            f->printStudyTable();

            // Liberation de memoire
            delete f;
        } else if (choice == 2) { // Generation de mots
            cout << "----- Creation de mots aleatoires -----\nEntrer la taille des mots a generer (une valeur elevee peut entrainer un temps de calcul long) : ";
            cin >> nb_letters;
            cout << "Nombre de generations (une valeur elevee peut entrainer un temps de calcul long) : ";
            cin >> nb_gen;
            fflush(stdin); // Pour ne pas prendre le \n au prochain cin

            f = new FileReader("ignore.conf", "empty.conf"); // Juste avec un fichier de separateurs

            cout << "Fichier de mots a conserver (laisser vide pour fichier par defaut) : \n";
            getline(cin, buff1);

            cout << "Generation aleatoire de mots de " << nb_letters \
            << " lettre(s) avec " << nb_gen << " generation(s) en utilisant le dictionnaire ";

            if(buff1.size() != 0  && is_readable(buff1)) {
                // Le dictionnaire existe
                cout << "personnel" << endl;
                f->read(buff1);
            } else {
                cout << "par defaut" << endl;
                f->read("dico.bk");
            }

            cout << "L'alphabet utilisé est l'alphabet francais accentue.\n\
            Seuls les mots du dictionnaire seront affichés avec le nombre de generations necessaire a leur obtenention" << endl;
            wg = new WordsGenerator("alphabet.az"); // Generation aleatoire de mots

            system("pause");

            for(unsigned long i = 0 ; i < nb_gen ; ++i) {
                string str = wg->rand(nb_letters);
                if(f->contains(str)) {
                    cout << str << "\t" << i+1 << endl;
                }
            }

            // Liberation de memoire
            delete f;
            delete wg;
        } else if (choice != 9) {
            cout << "Choix incorrect !" << endl;
            choice = -1;
        }
    }

    return 0;
}
