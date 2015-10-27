template<typename T>
Node<T>::Node(T p_value = T(), Node<T> * p_ls = 0, Node<T> * p_rs = 0) {
    m_value = p_value;
    m_ls = p_ls;
    m_rs = p_rs;
}

template<typename T>
Node<T>::Node(const Node & p_toCopy) {
    this->m_value = p_toCopy.getValue();
    this->setLeftSon(p_toCopy.getLeftSon());
    this->setRightSon(p_toCopy.getRightSon());
}

template<typename T>
Node<T>::~Node() {

}

template<typename T>
Node<T> & Node<T>::operator=(const Node<T> &) {

}

template<typename T>
T & Node<T>::getValue() const {

}

template<typename T>
Node<T> & Node<T>::getLeftSon() const {

}

template<typename T>
Node<T> & Node<T>::getRightSon() const {

}

template<typename T>
void Node<T>::setValue(const T &) {

}

template<typename T>
void Node<T>::setLeftSon(const Node &) {

}

template<typename T>
void Node<T>::setRightSon(const Node &) {

}
