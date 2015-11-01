#include "FileReader.h"
#include "BinarySearchTree.h"
#include "WordsGenerator.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    FileReader          fl("nawak.conf", "nawak.conf");
    WordsGenerator      wg("alphabet.az");

    fl.read("dico.bk");

    cout << "--- START of WORDS CREATION ---" << endl;
    for(unsigned long i = 0 ; i < 1000000 ; ++i) {
        string str = wg.rand();
        if(fl.contains(str)) {
            cout << str << "\t" << i+1 << endl;
        }
    }

    return 0;
}

