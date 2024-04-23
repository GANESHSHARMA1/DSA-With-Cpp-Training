#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    int priority;
    Node *next;

public:
    Node(int d, int p)
    {
        data = d;
        priority = p;
        next = nullptr;
    }

    int getData()
    {
        return data;
    }

    int getPriority()
    {
        return priority;
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *node)
    {
        next = node;
    }
};

Node *newNode(int d, int p)
{
    return new Node(d, p);
}

int peek(Node **head)
{
    return (*head)->getData();
}

void pop(Node **head)
{
    Node *temp = (*head);
    (*head) = (*head)->getNext();
    delete temp;
}

void push(Node **head, int d, int p)
{
    Node *start = *head;
    Node *temp = newNode(d, p);

    if ((*head)->getPriority() < p)
    {
        temp->setNext(*head);
        (*head) = temp;
    }
    else
    {
        while (start->getNext() != nullptr && start->getNext()->getPriority() > p)
        {
            start = start->getNext();
        }
        temp->setNext(start->getNext());
        start->setNext(temp);
    }
}

bool isEmpty(Node **head)
{
    return (*head) == nullptr;
}

int main()
{
    Node *q = newNode(4, 1);
    push(&q, 5, 2);
    push(&q, 6, 3);
    push(&q, 7, 0);

    while (!isEmpty(&q))
    {
        cout << " " << peek(&q);
        pop(&q);
    }

    return 0;
}