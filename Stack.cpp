#include <iostream>
using namespace std;

#define n 100

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int data)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = data;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int data = arr[top--];
        return data;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
    void display()
    {
        int temp = top;
        if (temp == -1)
        {
            cout << "Stack is Underflow!" << endl;
            return;
        }
        while (temp != -1)
        {
            cout << arr[temp--] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(3);
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    s.display();
    cout << s.empty() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;
    s.display();
    cout << s.empty() << endl;
}