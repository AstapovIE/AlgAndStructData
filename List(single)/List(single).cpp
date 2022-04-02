#include <iostream>

using namespace std;
//Односвязный список
template<typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T data);
    void push_first(T data);
    void pop_back();
    void pop_first();
    void clear();
    void print();
    void insert(T data, int index);
    void remove(int index);
    int get_size() { return Size; };
    T& operator [](const int index);

private:
    template<typename T>
    class Node
    {
    public:
        Node *pNext;
        T data;

        Node(T data = T(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T> *head;

};





template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    cout << "Destructor" << endl;
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void List<T>::push_first(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::pop_back()
{
    if (Size == 1) {
        pop_first();
    }
    else {
        Node<T>* previous = this->head;
        for (int i = 0; i < Size - 2; i++) {
            previous = previous->pNext;
        }

        Node<T>* toDel = previous->pNext;

        previous->pNext = nullptr;
        delete toDel;
        Size--;
    }
}

template<typename T>
void List<T>::pop_first()
{
    Node<T>* temp = head;
    head = head->pNext;

    delete temp;
    Size--;
}

template<typename T>
void List<T>::clear()
{
    while (Size) {
        pop_first();
    }
}

template<typename T>
void List<T>::print()
{
    cout << "Elements : ";
    if (Size>0) {
        Node<T>* current = this->head;
        while (current->pNext != nullptr) {
            cout << current->data << " ";
            current = current->pNext;
        }
        cout << current->data;
    }
    cout << endl;
    
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0) { push_first(data); }
    else {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        previous->pNext = new Node<T>(data, previous->pNext);
    }
    Size++;
}

template<typename T>
void List<T>::remove(int index)
{
    if (index == 0) { pop_first(); }
    else {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T>* toDel = previous->pNext;

        previous->pNext = toDel->pNext;

        delete toDel;
        Size--;
    }
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (counter != index) {
        current = current->pNext;
        counter++;
    }
    return current->data;
}



int main()
{
    List<int> list;
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_first(1);
    list.insert(5, 2);
   
    list.print();

    list.pop_first();
    
    list.print();
    list.remove(1);
    list.print();
    list.pop_back();
    list.print();
    list.pop_back();
    list.print();
    list.pop_back();
    list.print();


     
}
