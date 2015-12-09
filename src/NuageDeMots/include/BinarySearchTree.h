#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include <map>
#include "Node.h"

template<typename T>
class BinarySearchTree {
    protected:
        std::map<std::string,Node<T> >      m_abr;

    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree &);
        virtual ~BinarySearchTree();
        BinarySearchTree & operator=(const BinarySearchTree &);

        const T & operator[](int) const;

        bool add(const T &);
        unsigned int size() const;
        bool contains(const T &) const;
        void printAll() const;

        std::string toString() const;
        std::string sort() const;

    private:
        Node<T> ** search(const T &);
        void balance();

};

#include "BinarySearchTree.tpp"

#endif // BINARYSEARCHTREE
