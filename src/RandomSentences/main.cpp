#include <iostream>
#include <string>

#include "WordsGenerator.h"

using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    WordsGenerator 			wg;
    unsigned 				iter_number 	= 10;
    string 					sentence 		= "bleu";

    if(argc > 1) {
    	sentence = argv[1];
    }
    if(argc > 2) {
    	iter_number = atoi(argv[2]);
    }

    for(unsigned i = 0 ; i < iter_number ; ++i)
        wg.expectWord(sentence.c_str());

    return 0;
}
