#ifndef NODE_H
#define NODE_H

#include "Countable.h"

template <typename T>
class Node : public Countable {
    protected:
        T           m_value;

    public:
        Node(T);
        Node(const Node &);
        virtual ~Node();
        Node & operator=(Node &);

        T & getValue() const;
        void setValue(const T &);
};

#include "Node.tpp"

#endif // NODE_H
