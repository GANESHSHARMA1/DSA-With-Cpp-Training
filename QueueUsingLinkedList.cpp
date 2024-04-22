#include <iostream>
using namespace std;

class Queue
{
    int data;
    Queue *next;

public:
    Queue() {}
    Queue(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Queue *head = nullptr;
    Queue *tail = nullptr;

    void add(int data)
    {
        Queue *newVal = new Queue(data);
        if (head == nullptr)
        {
            head = tail = newVal;
            return;
        }
        tail->next = newVal;
        tail = newVal;
    }

    void remove()
    {
        if (head == nullptr)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        int data = head->data;
        head = head->next;
        cout << data << endl;
    }
};

int main()
{
    Queue q;
    q.add(12);
    q.add(23);
    q.remove();
    q.remove();
    q.remove();
    return 0;
}