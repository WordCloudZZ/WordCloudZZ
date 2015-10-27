#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
    protected:
        T           m_value;
        Node      * m_ls,
                  * m_rs;

    public:
        Node(T,Node*,Node*);
        Node(const Node &);
        virtual ~Node();
        Node & operator=(const Node &);

        T & getValue() const;
        Node & getLeftSon() const;
        Node & getRightSon() const;

        void setValue(const T &);
        void setLeftSon(const Node &);
        void setRightSon(const Node &);
};

#include "Node.tpp"

#endif // NODE_H
