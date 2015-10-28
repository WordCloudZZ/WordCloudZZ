#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include <stack>
#include "Node.h"

template<typename T>
class BinarySearchTree {
    protected:
        int                         m_size;
        Node<T>                   * m_tree;

    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree &);
        virtual ~BinarySearchTree();
        BinarySearchTree & operator=(const BinarySearchTree &);

        const T & at(int) const;
        bool add(const T &);
        bool erase(const T &);
        unsigned long long int size() const;
        unsigned long long int height() const;
        bool contains(const T &) const;
        void printAll() const;

        std::string toString() const;
        std::string sort() const;

    private:
        Node<T> & search(const T &) const;
        void balance();

};

#include "BinarySearchTree.tpp"

#endif // BINARYSEARCHTREE
