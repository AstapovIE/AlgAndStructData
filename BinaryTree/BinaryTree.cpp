#include <iostream>

using namespace std;

template<typename T>
class BinaryTree
{
private:
    template<typename T>
    class Node
    {
    public:
        T key;
        Node<T>* left;
        Node<T>* right;
        Node<T>* parent;

        Node(T key, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) {
            this->key = key;
            this->left = left;
            this->right = right;
            this->parent = parent;
        }
    };
    int size;
    Node<T>* head;

    void print_elem(Node<T>* current);

public:
    BinaryTree();
    ~BinaryTree();

    void get_size();
    bool find(T key);
    void insert(T key);
    void print();
    void remove(T key);
};


template<typename T>
void BinaryTree<T>::print_elem(Node<T>* current)
{
    if (current) {
        print_elem(current->left);
        cout << current->key << " ";
        print_elem(current->right);
    }
    
}   

template<typename T>
BinaryTree<T>::BinaryTree()
{
    head = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
}

template<typename T>
void BinaryTree<T>::get_size()
{
    cout << size << endl;;
}

template<typename T>
bool BinaryTree<T>::find(T key)
{
    Node<T>* current = this->head;
    while (current) {
        if (current->key == key) { return true; }
        if (current->key > key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}

template<typename T>
void BinaryTree<T>::insert(T key)
{
    if (head != nullptr)
    {
        Node<T>* current = this->head;
        while (current && current->key != key){
            if (current->key > key && current->left == nullptr) {
                current->left = new Node<T>(key);
                size++;
                return;
            }
            if (current->key < key && current->right == nullptr) {
                current->right = new Node<T>(key);
                size++;
                return;
            }
            if (current->key > key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
            
    }


    else { head = new Node<T>(key); size++; }
}

template<typename T>
void BinaryTree<T>::print()
{
    cout << "Elements:  ";
    print_elem(head);
    cout << endl;
}

template<typename T>
void BinaryTree<T>::remove(T key)
{

}


int main()
{
    BinaryTree<int> a;
    a.insert(5);
    a.insert(6);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.get_size();
    a.print();
}
