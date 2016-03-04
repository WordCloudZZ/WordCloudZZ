#include <iostream>
#include <string>

#include "WordsGenerator.h"

using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    unsigned 				iter_number 	= 10;
    string 					sentence 		= "random",
                            seed            = "Le hasard ne fait pas de phrase.",
                            alphabet        = "alpha.az",
                            arg;

    if(argc > 1) {
        arg = argv[1];
        if(arg=="-h") {
            cout << endl << "Usage:\n RandomSentences [option] [ <sentence> [ <iterations> [ <alphabet_file> ] ] ]" << endl << endl;
            cout << "Arguments:" << endl <<
            " <sentence>\t\tsentence to compute\n" <<
            " <iterations>\t\tnumber of iterations to compute\n" <<
            " <alphabet_file>\t\tfile containing the chosen alphabet\n" <<
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
    	alphabet = argv[3];
    }
    WordsGenerator 			wg(seed, alphabet.c_str());

    wg.studySentence(sentence, iter_number, cout);

    return 0;
}
