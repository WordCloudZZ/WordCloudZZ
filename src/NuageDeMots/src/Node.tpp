template<typename T>
Node<T>::Node(T p_value = T(), Node<T> * p_ls = 0, Node<T> * p_rs = 0) :
    Countable(), m_value(p_value), m_ls(p_ls), m_rs(p_rs) {

}

template<typename T>
Node<T>::Node(const Node & p_toCopy) : Countable(p_toCopy) {
    this->m_value = p_toCopy.getValue();
    this->setLeftSon(p_toCopy.getLeftSon());
    this->setRightSon(p_toCopy.getRightSon());
}

template<typename T>
Node<T>::~Node() {

}

template<typename T>
Node<T> & Node<T>::operator=(const Node<T> & p_toCopy) {
    if(*this != p_toCopy) {
        ((Countable*)this)->operator=(p_toCopy);
        this->m_value = p_toCopy.getValue();
        this->setLeftSon(p_toCopy.getLeftSon());
        this->setRightSon(p_toCopy.getRightSon());
    }
    return *this;
}

template<typename T>
T & Node<T>::getValue() const {
    return m_value;
}

template<typename T>
Node<T> & Node<T>::getLeftSon() const {
    return *m_ls;
}

template<typename T>
Node<T> & Node<T>::getRightSon() const {
    return m_rs;
}

template<typename T>
void Node<T>::setValue(const T & p_value) {
    m_value = p_value;
}

template<typename T>
void Node<T>::setLeftSon(const Node & p_ls) {
    m_ls = p_ls;
}

template<typename T>
void Node<T>::setRightSon(const Node & p_rs) {
    m_rs = p_rs;
}

