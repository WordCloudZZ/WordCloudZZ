template <typename T>
BinarySearchTree<T>::BinarySearchTree() : m_abr() {

}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree & p_toCopy) {
    m_abr = p_toCopy.m_abr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {

}

template <typename T>
BinarySearchTree<T> & BinarySearchTree<T>::operator=(const BinarySearchTree & p_toCopy) {
    m_abr = p_toCopy.m_abr;
    return *this;
}

template <typename T>
const T & BinarySearchTree<T>::operator[](int) const {
    return T();
}

template <typename T>
bool BinarySearchTree<T>::add(const T & p_toAdd) {
    bool                                retour      = true;
    auto                                it          = m_abr.find(p_toAdd);

    if(it != m_abr.end()) {
        m_abr.insert(std::pair<T, Node<T> >(p_toAdd, Node<T>(p_toAdd)));
    } else {
        it->second++;
    }

    return retour;
}

template <typename T>
unsigned int BinarySearchTree<T>::size() const {
    return m_abr.size();
}

template <typename T>
bool BinarySearchTree<T>::contains(const T & p_toFind) const {
    return (m_abr.find(p_toFind) != m_abr.end());
}

template <typename T>
void BinarySearchTree<T>::printAll() const {
    std::cout << "-- TREE CONTENT --\n" << std::endl;
    for(auto it = m_abr.begin() ; it != m_abr.end() ; ++it) {
        std::cout << it->second.getValue() << "\t#" << it->second.number() << std::endl;
    }
    std::cout << "\n-- END OF TABLE --" << std::endl;
}

template <typename T>
std::string BinarySearchTree<T>::toString() const {
    std::string str = "Arbre binaire de recherche (BinarySearchTree)";
    return str;
}

template <typename T>
std::string BinarySearchTree<T>::sort() const {
    std::string result;
    std::forward_list<Node<T> > sorted;
    sorted.push_front(Node<T>());
    for(int i = 0 ; i < size_ ; ++i) {
        for(int j = 0 ; j < table_[i].size() ; ++j) {
            typename std::forward_list<Node<T> >::iterator it = std::begin(sorted);
            typename std::forward_list<Node<T> >::iterator pit = it;
            while(it!=std::end(sorted) && (*it).number() < table_[i][j].number()) {
                pit = it;
                it++;
            }
            sorted.emplace_after(pit, table_[i][j]);
        }
    }
    for(auto it = std::begin(sorted); it!=std::end(sorted) ; ++it) {
        if((*it).getValue().size() > 0)
            std::cout << (*it).getValue() << "\t#" << (*it).number() << std::endl;
    }

    return result;
}

