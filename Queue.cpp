#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int n;
    int front;
    int back;

public:
    Queue(int n)
    {
        this->n = n;
        arr = new int[n];
        front = back = -1;
    }

    void push(int data)
    {
        if (back == n - 1)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (front == -1)
            front++;
        arr[++back] = data;
    }

    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        int data = arr[front];
        if (front == back)
        {
            front = back = -1;
        }
        else
            front++;
        cout << data << endl;
    }
};

int main()
{
    Queue q(10);
    q.pop();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    return 0;
}