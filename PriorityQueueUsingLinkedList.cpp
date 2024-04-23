#include <iostream>
using namespace std;

class Queue
{
private:
    int val;
    int priority;
    Queue *next;

public:
    Queue() {}
    Queue(int val)
    {
        this->val = val;
        this->priority = INT_MIN;
        this->next = nullptr;
    }

    Queue *head = nullptr;

    void enqueue(int val, int priority)
    {
        Queue *q = new Queue(val);
        q->priority = priority;
        if (head == nullptr || priority > head->priority)
        {
            q->next = head;
            head = q;
        }
        else
        {
            Queue *temp = head;
            while (temp != nullptr && temp->priority >= priority)
            {
                temp = temp->next;
            }
            q->next = temp->next;
            temp->next = q;
        }
    }

    void dequeue()
    {
        if (head == nullptr)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        int data = head->val;
        head = head->next;
        cout << data << endl;
    }

    void peek()
    {
        if (head == nullptr)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        int data = head->val;
        cout << data << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10, 2);
    q.enqueue(14, 4);
    q.enqueue(15, 4);
    q.enqueue(12, 5);
    q.peek();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}