#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    Stack(int s)
    {
        size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    // int mid = size / 2;

    bool isFull()
    {
        return top1 == top2;
    }

    void push1(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top1] = data;
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        int val = arr[top1--];
        cout << val << endl;
    }

    void push2(int data)
    {
        if (isFull())
        {
            cout << "Stack OverFlow" << endl;
            return;
        }
        arr[--top2] = data;
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack UnderFlow" << endl;
            return;
        }
        int data = arr[top2++];
        cout << data << endl;
    }
};

int main()
{
    Stack s(4);
    s.push1(1);
    s.push1(1);
    s.push1(1);
    s.push2(2);
    s.push2(2);
    s.pop1();
    // s.push1(3);
    s.pop1();
    s.pop1();
    s.pop2();
    s.pop2();
    s.pop2();
    return 0;
}