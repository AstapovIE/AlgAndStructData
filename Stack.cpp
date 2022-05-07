#include <iostream>

using namespace std;

class Stack
{
public:
    Stack();
    ~Stack() { delete[] buffer; }

    void push(int a);
    void pop();
    void print();

private:
    int* buffer;
    int  buffSize;
    int  head;
    int  size;

    void resize();
};

int main()
{
    Stack a;
    a.push(2);
    a.pop();
    a.push(1);
    a.push(3);
    a.pop();
    a.push(5);
    a.push(5);
    a.push(5);
    a.print();
}


Stack::Stack()
{
    buffSize = 4;
    buffer = new int[buffSize];
    head = 0;
    size = 0;
}

void Stack::push(int a)
{
    if (head + 1 == buffSize) { resize(); }

    buffer[head] = a;
    ++head;
    ++size;
}

void Stack::pop()
{
    --head;
}

void Stack::print()
{
    cout << this->buffSize << endl;
    for (int i = 0; i <= head - 1; i++)
    {
        cout << buffer[i];
    }
    cout << endl;
}

void Stack::resize()
{
    int newsize = buffSize * 2;
    int* newbuff = new int[newsize];

    for (int i = 0; i < head; i++) {
        newbuff[i] = buffer[i];
    }

    delete[] buffer;

    buffer = newbuff;
    buffSize = newsize;
}