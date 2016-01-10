// Includes Qt
#include "mainwindow.h"
#include <QApplication>
/*
// Includes c++
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string filePath = "";

    QApplication a(argc, argv); // Objet de l'app
    MainWindow w; // Fenetre principale
    w.show(); // Affiche la fenetre


    return a.exec();
}
*/

#include <iostream>
#include <string>
#include <cstring>

#include "FileReader.h"
#include "BinarySearchTree.h"
#include "Hashtable.h"

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
    std::string                         buff1           = "",
                                        buff2           = "",
                                        buff3           = "",
                                        buff[3]         = {"hill.bk","ignore.conf","filereader.conf"};
    unsigned                            choice          = 0,
                /** Choix du mode de l'interface : 0-ligne de commande;1-menu console;2-interface graphique */
                                        output_choice   = 2, //!
                                        argStringNumber = 0;
    IFileReader                       * analyseur       = NULL;
    bool                                useABRE         = true;
    setlocale(LC_ALL, "");

    // traitement des arguments
    for(int i = 1 ; i < argc ; ++i) {
        if(argv[i][0]=='-' && strlen(argv[i])==2) {
            string arg = argv[i];
            for(char c : arg) {
                if(c=='X') { // ligne de commande
                    output_choice = 0;
                } else if(c=='v') { // menu console
                    output_choice = 1;
                } else if(c=='x') { // interface graphique
                    output_choice = 2;
                } else if(c=='h') { // interface graphique
                    useABRE = false;
                } else if(c=='a') { // interface graphique
                    useABRE = true;
                } else {
                    output_choice = -1;
                }
            }
        } else {
            buff[argStringNumber++] = argv[i];
        }
    }

    if(output_choice==0) {      // console simple
        if(useABRE)
            analyseur = new FileReader<BinarySearchTree>(buff[1], buff[2]);
        else
            analyseur = new FileReader<Hashtable>(buff[1], buff[2]);   // initialisation (ignore,separateurs)
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
                    if(useABRE)
                        analyseur = new FileReader<BinarySearchTree>(buff1, buff2);
                    else
                        analyseur = new FileReader<Hashtable>(buff1, buff2);
                } else if ((buff1.size() == 0 && buff2.size() != 0) && (is_readable(buff2))) {
                    // Pas de fichier de mots et l'autre fichier existe
                    cout << "Utilisation de s�parateurs personnels" << endl;
                    if(useABRE)
                        analyseur = new FileReader<BinarySearchTree>("ignore.conf", buff2);
                    else
                        analyseur = new FileReader<Hashtable>("ignore.conf", buff2);
                } else if ((buff2.size() == 0 && buff1.size() != 0) && (is_readable(buff1))) {
                    // Pas de separateurs
                    cout << "Utilisation de la liste personnelle de mots � ignorer" << endl;
                    if(useABRE)
                        analyseur = new FileReader<BinarySearchTree>(buff1, "filereader.conf");
                    else
                        analyseur = new FileReader<Hashtable>(buff1, "filereader.conf");
                } else {
                    // On a rien
                    cout << "** Utilisation des fichiers de configuration par d�faut" << endl;
                    if(useABRE)
                        analyseur = new FileReader<BinarySearchTree>();
                    else
                        analyseur = new FileReader<BinarySearchTree>();
                }

                if(buff3.size() == 0 || !is_readable(buff3)) {
                    cout << "** Utilisation du fichier par defaut" << endl;
                    buff3.clear();
                    buff3="hill.bk";
                }

                cout << "\nL'analyse va d�buter et les resultats seront immediatement affiches" << endl;
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
        std::string filePath = "";

        QApplication a(argc, argv); // Objet de l'app
        MainWindow w; // Fenetre principale
        w.show(); // Affiche la fenetre


        return a.exec();
    } else {    // erreur
        cout << "Argument inconnu" << endl;
    }


    return 0;
}
