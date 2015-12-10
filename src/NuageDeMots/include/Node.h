#ifndef NODE_H
#define NODE_H

#include "Countable.h"

template <typename T>
class Node : public Countable {
    protected:
        T           m_value;

    public:
        Node(T);
        virtual ~Node();
        Node & operator=(Node &);

        T getValue();
        void setValue(const T &);
};

#include "Node.tpp"

#endif // NODE_H
