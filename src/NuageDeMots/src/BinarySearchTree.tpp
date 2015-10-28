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
	Node<T> * cur = &m_tree,
            * tmp = nullptr;
	std::stack<Node<T> > pile;

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
    Node<T> * cur = m_tree,
            **prev= &m_tree;
    bool      retour;
    while(cur!=nullptr && cur.getValue()!=p_toAdd) {
        prev = &(cur->getLeftRight());
        cur = cur->getRightSon();
        if(p_toAdd <= cur->getValue()) {
            prev = &(cur->getLeftSon());
            cur = cur->getLeftSon();
        }
    }
    if(cur==nullptr) {
        *prev = p_toAdd;
        retour = true;
    } else {
        (*prev)++;
        retour = false;
    }
    return retour;
}

template <typename T>
bool BinarySearchTree<T>::erase(const T &) {

}

template <typename T>
unsigned long long int BinarySearchTree<T>::size() const {

}

template <typename T>
unsigned long long int BinarySearchTree<T>::height() const {

}

template <typename T>
bool BinarySearchTree<T>::contains(const T &) const {

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
Node<T> & BinarySearchTree<T>::search(const T &) const {

}

template <typename T>
void BinarySearchTree<T>::balance() {

}

