#include "FileReader.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    BinarySearchTree<int> ABR;
cout << "BLEU " << ABR.m_tree << "\t" << &(ABR.m_tree->m_ls) << "\t" << &(ABR.m_tree->m_rs) << endl;
    ABR.add(5);
    cout << "BLEU " << ABR.m_tree << "\t" << &(ABR.m_tree->m_ls) << "\t" << &(ABR.m_tree->m_rs) << endl;
    ABR.add(19);
    ABR.add(1);
    ABR.add(23);
    ABR.add(1);
    ABR.add(12);
    ABR.add(50);
    ABR.add(100);
    ABR.add(7);

    cout << "BLEU " << ABR.m_tree << "\t"  << &(ABR.m_tree) << "\t" << &(ABR.m_tree->m_ls) << "\t" << &(ABR.m_tree->m_rs) << endl;

    return 0;
}

