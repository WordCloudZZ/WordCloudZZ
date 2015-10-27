#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include "Node.h"

template<typename T>
class BinarySearchTree {

    private:


    protected:
        int                         m_size;
        Node<T>                   * m_tree;

    public:
        BinarySearchTree();
        virtual ~BinarySearchTree();
};

#include "BinarySearchTree.tpp"

#endif // BINARYSEARCHTREE
