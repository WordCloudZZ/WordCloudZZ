#include <iostream>
#include <string>
#include <cstring>

#include "FileReader.h"
#include "BinarySearchTree.h"

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

int main(int argc, char** argv) {
    std::string     buff1           = "",
                    buff2           = "",
                    buff3           = "",
                    buff[3]         = {"hill.bk","ignore.conf","filereader.conf"};
    unsigned        choice          = 0,
                    /** Choix du mode de l'interface : 0-ligne de commande;1-menu console;2-interface graphique */
                    output_choice   = 0,
                    argStringNumber = 0;
    FileReader    * analyseur       = NULL;

    setlocale(LC_ALL, "");

    // traitement des arguments
    for(int i = 1 ; i < argc ; ++i) {
        if(argv[i][0]=='-' && strlen(argv[i])==2) {
            if(argv[i][1]=='X') { // ligne de commande
                output_choice = 0;
            } else if(argv[i][1]=='v') { // menu console
                output_choice = 1;
            } else if(argv[i][1]=='x') { // interface graphique
                output_choice = 2;
            } else {
                output_choice = -1;
            }
        } else {
            buff[argStringNumber++] = argv[i];
        }
    }

    if(output_choice==0) {      // console simple
        analyseur = new FileReader(buff[1], buff[2]);       // initialisation (ignore,separateurs)
        analyseur->read(buff[0]);                          // lecture du fichier
        analyseur->printStudyTable();                   // affichage des resultats
        delete analyseur;                               // liberation de la memoire
    } else if(output_choice==1) {   // menu console
        while(choice != 9) {
            cout << "-------------------- Nuage de Mots --------------------\n" << endl;
            cout << \
                "Selectionner une action :\
                \n\t1 : Nuage de mots a partir de fichier texte\
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
                    analyseur = new FileReader(buff1, buff2);
                } else if ((buff1.size() == 0 && buff2.size() != 0) && (is_readable(buff2))) {
                    // Pas de fichier de mots et l'autre fichier existe
                    cout << "Utilisation de sepatateurs personnels" << endl;
                    analyseur = new FileReader("ignore.conf", buff2);
                } else if ((buff2.size() == 0 && buff1.size() != 0) && (is_readable(buff1))) {
                    // Pas de separateurs
                    cout << "Utilisation de la liste personnelle de mots a ignorer" << endl;
                    analyseur = new FileReader(buff1, "filereader.conf");
                } else {
                    // On a rien
                    cout << "** Utilisation des fichiers de configuration par defaut" << endl;
                    analyseur = new FileReader();
                }

                if(buff3.size() == 0 || !is_readable(buff3)) {
                    cout << "** Utilisation du fichier par defaut" << endl;
                    buff3.clear();
                    buff3="hill.bk";
                }

                cout << "\nL'analyse va débuter et les resultats seront immediatement affiches" << endl;
                system("pause"); // Attente de confirmation

                analyseur->read(buff3.c_str());

                // Affichage de la liste de mots triee par occurences
                analyseur->printStudyTable();

                // Liberation de memoire
                delete analyseur;
            } else if (choice != 9) {
                cout << "Choix incorrect !" << endl;
                choice = -1;
            }
        }
    } else if(output_choice==2) {   // graphique
        cout << "L'interface graphique n'est pas encore prete :$" << endl;
    } else {    // erreur
        cout << "Argument inconnu" << endl;
    }


    return 0;
}
