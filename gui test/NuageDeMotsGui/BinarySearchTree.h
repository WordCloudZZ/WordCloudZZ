#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include <map>
#include <algorithm>
#include "Node.h"

template<typename T>
class BinarySearchTree {
    protected:
        std::map<T,Node<T> >      m_abr;

    public:
        BinarySearchTree();
        /*BinarySearchTree(const BinarySearchTree &);*/
        virtual ~BinarySearchTree();
        /*BinarySearchTree & operator=(const BinarySearchTree &);*/

        /*const T & operator[](int) const;*/

        bool add(const T &);
        unsigned int size() const;
        bool contains(const T &) const;
        void printAll() const;

        std::string toString() const;
        std::forward_list<std::string> stringList() const;
        std::string sort();
        void deletePlurals();
};

#include "BinarySearchTree.tpp"

#endif // BINARYSEARCHTREE
