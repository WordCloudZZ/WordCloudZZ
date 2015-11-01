template <typename T>
BinarySearchTree<T>::BinarySearchTree() : m_size(0), m_tree(nullptr) {

}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree & p_toCopy) {
    m_tree = p_toCopy.m_tree;
    m_size = p_toCopy.m_size;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	Node<T> * cur = m_tree,
            * tmp = nullptr;
	std::stack<Node<T>*> pile;

	while(cur != nullptr) {
            pile.push(cur->getRightSon());
            tmp = cur;
            cur = cur->getLeftSon();
            delete tmp;
        while(cur == nullptr && !pile.empty()) {
            cur = pile.top();
            pile.pop();
        }
	}
}

template <typename T>
BinarySearchTree<T> & BinarySearchTree<T>::operator=(const BinarySearchTree & p_toCopy) {
    m_tree = p_toCopy.m_tree;
    m_size = p_toCopy.m_size;
    return *this;
}

template <typename T>
const T & BinarySearchTree<T>::at(int) const {

}

template <typename T>
bool BinarySearchTree<T>::add(const T & p_toAdd) {
    bool retour;
    Node<T> ** prev = search(p_toAdd);      /// recherche du precedent de la valeur
    std::cout << prev << "\t" << (*prev) << std::endl;
    if(*prev==nullptr) {        /// si la valeur n'a pas ete trouve
        (*prev) = new Node<T>(p_toAdd,0,0);  /// on l'ajoute en tant que feuille
        m_size++;               /// on augmente la taille
        retour = true;
    } else {            /// si la valeur est deja presente
        //(**prev)++;          /// on incremente son nombre d'occurences
        retour = false;
    }
    return retour;
}

template <typename T>
bool BinarySearchTree<T>::erase(const T &) {
    return false;
}

template <typename T>
unsigned long long int BinarySearchTree<T>::size() const {
    return m_size;
}

template <typename T>
unsigned long long int BinarySearchTree<T>::height() const {

}

template <typename T>
bool BinarySearchTree<T>::contains(const T & p_toFind) const {
    bool retour = false;
    Node<T> ** prev = search(p_toFind);      /// recherche du precedent de la valeur
    if(*prev!=nullptr) {        /// si on a trouve la valeur
        retour = true;
    }
    return retour;
}

template <typename T>
void BinarySearchTree<T>::printAll() const {

}

template <typename T>
std::string BinarySearchTree<T>::toString() const {

}

template <typename T>
std::string BinarySearchTree<T>::sort() const {

}

template <typename T>
Node<T> ** BinarySearchTree<T>::search(const T & p_toFind) {
    Node<T> * cur = m_tree,
            **prev= &m_tree;
    while(cur!=nullptr && cur->getValue()!=p_toFind) {
        if(p_toFind <= cur->getValue()) {
            cur = cur->getLeftSon();
        } else {
            cur = cur->getRightSon();
        }
        prev = &cur;
    }
    return prev;
}

template <typename T>
void BinarySearchTree<T>::balance() {

}

