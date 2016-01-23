#include <iostream>
#include <string>

#include "WordsGenerator.h"

using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    unsigned 				iter_number 	= 10;
    string 					sentence 		= "Bleu",
                            seed            = "Le hasard ne fait pas de phrase.",
                            arg;

    if(argc > 1) {
        arg = argv[1];
        if(arg=="-h") {
            cout << endl << "Usage:\n RandomSentences [option] [ <sentence> [ <iterations> [ <random_seed> ] ] ]" << endl << endl;
            cout << "Arguments:" << endl <<
            " <sentence>\t\tsentence to compute\n" <<
            " <iterations>\t\tnumber of iterations to compute\n" <<
            " <random_seed>\t\tseed for the MT generator\n" <<
            "\nOptions:\n -h\t\t\tdisplay this helpful text\n" << endl;
            exit(0);
        } else {
            sentence = argv[1];
        }
    }
    if(argc > 2) {
    	iter_number = atoi(argv[2]);
    }
    if(argc > 3) {
    	seed = argv[3];
    }
    WordsGenerator 			wg(seed);

    wg.studySentence(sentence, iter_number, cout);

    return 0;
}
