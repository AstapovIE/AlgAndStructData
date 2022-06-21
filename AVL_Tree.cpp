#include <iostream>
#include <algorithm>

using namespace std;


class AvlTree 
{
private:
    class Node
    {
    public:
        int key;
        int height;
        Node* left;
        Node* right;
        Node(int key, Node* left = nullptr, Node* right = nullptr, int height = 0) {
            this->key = key;
            this->left = left;
            this->right = right;
            this->height = height;
        }

    };

    Node* root;

    Node* insert(int x, Node* t) {
        if (t == nullptr) {
            t = new Node(x);
        }
        else if (x < t->key)
        {
            t->left = insert(x, t->left);

            if (get_height(t->left) - get_height(t->right) == 2) {
                if (x < t->left->key)
                    t = smallRightRotate(t);
                else
                    t = bigRightRotate(t);
            
            }
        }
        else if (x > t->key)
        {
            t->right = insert(x, t->right);

            if (get_height(t->right) - get_height(t->left) == 2) {
                if (x > t->right->key)
                    t = smallLeftRotate(t);
                else
                    t = bigLeftRotate(t);

            }
        }

        t->height = max(get_height(t->left), get_height(t->right)) + 1;
        return t;
    }

    Node* smallLeftRotate(Node* t) {
        if (t->right != nullptr) {
            Node* s = t->right;
            t->right = s->left;
            s->left = t;
            t->height = max(get_height(t->left), get_height(t->right)) + 1;
            s->height = max(get_height(t->right), t->height) + 1;
            return s;
        }
        
        return t;
    }

    Node* bigLeftRotate(Node* t) {
        t->right = smallRightRotate(t->right);
        return smallLeftRotate(t);
    }

    Node* smallRightRotate(Node* t) {
        if (t->left != nullptr) {
            Node* s = t->left;
            t->left = s->right;
            s->right = t;
            t->height = max(get_height(t->left), get_height(t->right)) + 1;
            s->height = max(get_height(s->left), t->height) + 1;
            return s;
        }
        return t;
    }

    Node* bigRightRotate(Node* t) {
        t->left = smallLeftRotate(t->left);
        return smallRightRotate(t);
    }

    int get_height(Node* t)
    {
        return (t == nullptr ? -1 : t->height);
    }

    void print(Node* t) {
        if (t == nullptr) {return; }
        print(t->left);
        cout << t->key << " ";
        print(t->right);
    }

public:
    AvlTree();
    void insert(int key);
    void print();

    
};


AvlTree::AvlTree()
{
    root = nullptr;
}

void AvlTree::insert(int key)
{
    root = insert(key, root);
}

void AvlTree::print()
{
    print(root);
    cout << endl;
}



int main()
{
    AvlTree a;
    a.insert(5);
    a.print();
    a.insert(8);
    a.print();
    a.insert(12);
    a.print();
    a.insert(11);
    a.print();
    a.insert(7);
    a.print();
    a.insert(6);
    a.print();
    a.insert(9);
    a.print();
    a.insert(10);
    a.print();
    a.insert(1);
    a.print();
    a.insert(4);
    a.print();
}