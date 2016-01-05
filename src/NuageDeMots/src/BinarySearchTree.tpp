template <typename T>
BinarySearchTree<T>::BinarySearchTree() : m_abr() {

}
/*
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree & p_toCopy) {
    m_abr = p_toCopy.m_abr;
}
*/
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {

}
/*
template <typename T>
BinarySearchTree<T> & BinarySearchTree<T>::operator=(const BinarySearchTree & p_toCopy) {
    m_abr = p_toCopy.m_abr;
    return *this;
}
*//*
template <typename T>
const T & BinarySearchTree<T>::operator[](int) const {
    return T();
}
*/
template <typename T>
bool BinarySearchTree<T>::add(const T & p_toAdd) {
    bool                                        retour      = true;
    typename std::map<T, Node<T> >::iterator    it          = m_abr.find(p_toAdd);

    if(it == m_abr.end()) {
        it = m_abr.insert(std::pair<T, Node<T> >(p_toAdd, Node<T>(p_toAdd))).first;
    }
    it->second++;

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
/*
    class CompPair {
        bool operator()(std::pair<T, Node<T> > & a, std::pair<T, Node<T> > & b){
            return a.second.number() < b.second.number();
        }
    } bob;

    class CompNode {
        bool operator()(Node<std::string> & a, Node<std::string> & b){
            return a.number() < b.number();
        }
    } bib;

    std::string result;
    std::forward_list<Node<T> > sorted;
    std::vector<Node<std::string> > trie;
    for(auto n : m_abr) {
        trie.push_back(n.second);
    }
    sort(trie.begin(), trie.end(), bib);
auto po = trie.begin();
std::cout << po->number() << std::endl;
//    std::cout << "Test " << bob(m_abr.begin(), m_abr.begin()) << std::endl;
/*
    sorted.push_front(m_abr.begin()->second);
    for(auto j = ++(m_abr.begin()) ; j != m_abr.end() ; ++j) {
        typename std::forward_list<Node<T> >::iterator it = std::begin(sorted);
        typename std::forward_list<Node<T> >::iterator pit = it;
        while(it!=std::end(sorted) &&
              (*it).number() <
              j->second.number()) {
            pit = it;
            it++;
        }
        sorted.emplace_after(pit, j->second);
    }
    for(auto it = sorted.begin(); it != sorted.end() ; ++it) {
        if((*it).getValue().size() > 0)
            std::cout << (*it).getValue() << "\t#" << (*it).number() << std::endl;
    }
*//*
    return result;*/
}

