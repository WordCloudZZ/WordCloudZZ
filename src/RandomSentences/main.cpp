#include <iostream>
#include <string>

#include "WordsGenerator.h"

using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    unsigned 				iter_number 	= 10;
    string 					sentence 		= "bleu",
                            seed            = "Le hasard ne fait pas de phrase.";

    if(argc > 1) {
    	sentence = argv[1];
    }
    if(argc > 2) {
    	iter_number = atoi(argv[2]);
    }
    if(argc > 3) {
    	seed = argv[3];
    }
    WordsGenerator 			wg(seed);

    wg.studySentence(sentence, iter_number);

    return 0;
}
