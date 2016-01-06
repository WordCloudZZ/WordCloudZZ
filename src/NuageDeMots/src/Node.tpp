template<typename T>
Node<T>::Node(T p_value /*= T()*/) : Countable(), m_value(p_value) {

}

template<typename T>
Node<T>::~Node() {

}

template<typename T>
T Node<T>::getValue() {
    return m_value;
}

template<typename T>
void Node<T>::setValue(const T & p_value) {
    m_value = p_value;
}

