#ifndef NODE_H
#define NODE_H

#include "Countable.h"

template <typename T>
class Node : public Countable {
    protected:
        T           m_value;
public:        Node      * m_ls,
                  * m_rs;

    public:
        Node(T,Node*,Node*);
        Node(const Node &);
        virtual ~Node();
        Node & operator=(Node &);

        T & getValue();
        Node<T> * getLeftSon();
        Node<T> * getRightSon();

        void setValue(const T &);
        void setLeftSon(const Node *);
        void setRightSon(const Node *);
};

#include "Node.tpp"

#endif // NODE_H
