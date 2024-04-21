#include <iostream>
using namespace std;

#define n 100

class Stack
{
    char *arr;
    int top;

public:
    Stack()
    {
        arr = new char[n];
        top = -1;
    }

    void push(char data)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = data;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        char data = arr[top--];
        cout << data << endl;
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top] << endl;
    }
    void balancedParanthesis(string s)
    {
        for (char ch : s)
        {
            if (ch == '(')
            {
                push(ch);
            }
            else if (ch == ')' && arr[top] == '(')
            {
                pop();
            }
        }
        if (top == -1)
        {
            cout << "Balanced" << endl;
        }
        else
        {
            cout << "Unbalanced" << endl;
        }
    }
};

int main()
{
    Stack s;
    s.balancedParanthesis("()()");
    return 0;
}