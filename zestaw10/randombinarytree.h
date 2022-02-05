#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

template <typename T>
struct BSTNode {
// the default access mode and default inheritance mode are public
    T value;
    BSTNode *left, *right;
    //BSTNode *parent;   // używane w pewnych zastosowaniach
    // kostruktor domyślny
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    BSTNode(const T& item, BSTNode *le=nullptr, BSTNode *ri=nullptr) :
        value(item), left(le), right(ri) {} // konstruktor
    ~BSTNode() {} // destruktor
};
// Szablon dla przypadkowego drzewa binarnego.
template <typename T>
class RandomBinaryTree {
    BSTNode<T> *root;
public:
    RandomBinaryTree() : root(nullptr) {} // konstruktor domyślny
    ~RandomBinaryTree() { clear(); } // trzeba wyczyścić
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root->value; } // podgląd korzenia
    void insert(const T& item) { root = insert(root, item); }
    //void remove(const T& item); // na razie nie usuwamy elementów
    // Szukając element dostajemy wskaźnik do elementu lub nullptr.
    T* search(const T& item) const {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    void iter_preorder();
    void iter_inorder(); // trudne
    void iter_postorder(); // trudne
    void bfs(); // przejście poziomami (wszerz)
    void clear() { clear(root); root = nullptr; }
    void display() { display(root, 0); }

    // Metody bezpośrednio odwołujące się do node.
    // Mogą działać na poddrzewie.
    void clear(BSTNode<T> *node);
    BSTNode<T> * insert(BSTNode<T> *node, const T& item); // zwraca nowy korzeń
    BSTNode<T> * search(BSTNode<T> *node, const T& item) const;
    void preorder(BSTNode<T> *node);
    void inorder(BSTNode<T> *node);
    void postorder(BSTNode<T> *node);
    void display(BSTNode<T> *node, int level);
    virtual void visit(BSTNode<T> *node) {
        assert(node != nullptr);
        std::cout << "visiting " << node->value << std::endl;
    }
    int calc_leafs_rek();
    int calc_leafs_rek(BSTNode<T> *node);
    int calc_leafs_iter();
};
// Wyświetlanie obróconego (counterclockwise) drzewa binarnego.
template <typename T>
void RandomBinaryTree<T>::display(BSTNode<T> *node, int level) {
    if (node == nullptr) return;
    display(node->right, level + 1);
    std::cout << std::string(3 * level, ' ') << node->value << std::endl;
    display(node->left, level + 1);
}
#include <cstdlib>   // std::rand(), RAND_MAX, std::srand()

template <typename T>
BSTNode<T> * RandomBinaryTree<T>::insert(BSTNode<T> *node, const T& item) {
    if (node == nullptr) {
        return new BSTNode<T>(item);
    }
    if (std::rand() % 2) { // można lepiej
        node->left = insert(node->left, item);
    } else {
        node->right = insert(node->right, item);
    }
    return node; // zwraca nowy korzen
}
template <typename T>
BSTNode<T> * RandomBinaryTree<T>::search(BSTNode<T> *node, const T& item) const {
    if (node == nullptr || node->value == item) {
        return node;
    }
    T* ptr;
    ptr = search(node->left, item);
    if (ptr == nullptr) {
        ptr = search(node->right, item);
    }
    return ptr;
}

template <typename T>
void RandomBinaryTree<T>::bfs() {
    if (root == nullptr) return;
    std::queue<BSTNode<T>*> Q; // wskaźniki do wezłów
    BSTNode<T> *node = root;
    Q.push(node);
    while (!Q.empty()) {
        node = Q.front(); // podglądamy
        Q.pop();        // usuwamy z kolejki
        visit(node); // tu jest właściwe przetworzenie węzła
        if (node->left != nullptr)
            Q.push(node->left);
        if (node->right != nullptr)
            Q.push(node->right);
    }
}

template <typename T>
void RandomBinaryTree<T>::inorder(BSTNode<T> *node) {
    if (node == nullptr) return;
    inorder(node->left);
    visit(node);
    inorder(node->right);
}
template <typename T>
void RandomBinaryTree<T>::preorder(BSTNode<T> *node) {
    if (node == nullptr) return;
    visit(node);
    preorder(node->left);
    preorder(node->right);
}
template <typename T>
void RandomBinaryTree<T>::postorder(BSTNode<T> *node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    visit(node);
}

template <typename T>
void RandomBinaryTree<T>::iter_preorder() {
    if (root == nullptr) return;
    std::stack<BSTNode<T>*> S; // wskaźniki do węzłów
    BSTNode<T> *node = root;
    S.push(node);
    while (!S.empty()) {
        node = S.top(); // podglądamy
        S.pop();        // usuwamy ze stosu
        visit(node); // tu jest właściwe przetworzenie węzła
        if (node->right != nullptr) // najpierw prawe poddrzewo!
            S.push(node->right);
        if (node->left != nullptr)
            S.push(node->left);
    }
}

template <typename T>
int RandomBinaryTree<T>::calc_leafs_rek() {

   return calc_leafs_rek(root);
    
}  

template <typename T>
int RandomBinaryTree<T>::calc_leafs_rek(BSTNode<T> *node) {
    if (node == nullptr) {
        return 0;
    }

    if (node-> right == nullptr || node -> left == nullptr) {
        return 1;
    }

    return calc_leafs_rek(node->left)+calc_leafs_rek(node->right);
}

template <typename T>
int RandomBinaryTree<T>::calc_leafs_iter() {
    std::list<BSTNode<T>*>kolejka;
    if (root==nullptr){
        return 0;
    }

    kolejka.push_back(root);
    int licznik = 0;
    while (kolejka.size()>0) {
        BSTNode <T> *node = kolejka.front();
        kolejka.pop_front();
        if (node->right ==nullptr || node->left == nullptr) {
            licznik++;
           
        }
        else {
           if  (node->right!=nullptr) {
               kolejka.push_back(node->right);
           }

           if (node->left!=nullptr) {
               kolejka.push_back(node->left);

           }
        }
    }

    return licznik;


}

template <typename T>
void RandomBinaryTree<T>::clear(BSTNode<T> *node){

}


