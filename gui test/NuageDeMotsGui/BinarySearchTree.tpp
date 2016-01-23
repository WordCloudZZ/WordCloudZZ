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
std::string BinarySearchTree<T>::sort() {

    class CompPair {
        public:
        bool operator()(const std::pair<T, Node<T> > & a, const std::pair<T, Node<T> > & b){
            return a.second.number() < b.second.number();
        }
    } bob;

    std::string result;
    std::forward_list<std::pair<T,Node<T> > > sorted;
    std::vector<std::pair<T,Node<T> > > trie;
    for(auto n : m_abr) {
        trie.push_back(n);
    }
    std::sort(trie.begin(), trie.end(), bob);

    for(auto po : trie)
        std::cout << po.second.getValue() << "\t#" << po.second.number() << std::endl;

    return result;
}

template <typename T>
void BinarySearchTree<T>::deletePlurals() {
    for(auto pairWord : m_abr) {
            Node<T> * word = &(pairWord.second);
            if(word->getValue().c_str()[word->getValue().size()-1] == 's' || word->getValue().c_str()[word->getValue().size()-1] == 'x') {
                std::string singulier = word->getValue().substr(0,word->getValue().length()-1);
                auto iteratorOnSingular = m_abr.find(singulier);
                if(iteratorOnSingular != m_abr.end()) {
                    iteratorOnSingular->second.setNumber(iteratorOnSingular->second.number()+word->number());
                    m_abr.erase(word->getValue());
                }
            }

    }
}

template <typename T>
std::forward_list<std::string> BinarySearchTree<T>::stringList() const {
    std::forward_list<std::string> list;
    list.push_front("Not implemented for this type");
    // TODO : implements

    return list;
}
