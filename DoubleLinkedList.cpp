#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

int size = 0;
Node *head = nullptr;
Node *tail = nullptr;

void insertAtHead(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = tail = newNode;
        size++;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    size++;
}

void insertAtLast(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = tail = newNode;
        size++;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    size++;
}

void insertAtPos(int data, int pos)
{
    Node *newNode = new Node(data);
    if (pos < 0 || pos > size)
    {
        cout << "The Position index doesn't exist inside LinkedList" << endl;
        return;
    }
    if (pos == 0)
    {
        insertAtHead(data);
        return;
    }
    if (pos == size)
    {
        insertAtLast(data);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    size++;
}

void printReversedLinkedList()
{
    if (head == nullptr)
    {
        cout << "The Linked List is Empty!" << endl;
        return;
    }
    Node *temp = tail;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
    delete temp;
}

void deleteAtHead()
{
    if (head == nullptr)
    {
        cout << "List is Empty!" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        head = tail = nullptr;
        return;
    }
    head = head->next;
    head->prev = nullptr;
    size--;
}

void deleteAtTail()
{
    if (head == nullptr)
    {
        cout << "Linked List is Empty! " << endl;
        return;
    }
    if (head->next == nullptr)
    {
        head = tail = nullptr;
        return;
    }
    tail = tail->prev;
    tail->next = nullptr;
    size--;
}

void deleteByValue(int val)
{
    Node *temp = head;
    if (head == nullptr)
    {
        cout << "Linked List is Empty!" << endl;
        return;
    }
    if (head->data == val)
    {
        deleteAtHead();
        return;
    }
    while (temp != nullptr && temp->data != val)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "This Value = " << val << " is not present in this code!" << endl;
        return;
    }
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }

    delete temp;
}

void printLinkedList()
{
    if (head == nullptr)
    {
        cout << "The Linked List is Empty!" << endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insertAtHead(10);
    insertAtHead(20);
    printLinkedList();
    insertAtLast(30);
    insertAtLast(40);
    printLinkedList();
    insertAtPos(15, 1);
    printLinkedList();
    insertAtPos(25, 3);
    printLinkedList();
    insertAtPos(50, 5);
    printLinkedList();
    insertAtPos(5, 0);
    printLinkedList();
    // printReversedLinkedList();
    insertAtPos(90, 8);
    printLinkedList();
    printReversedLinkedList();
    printLinkedList();
    deleteAtHead();
    printLinkedList();
    deleteAtTail();
    printLinkedList();
    deleteByValue(33);
    printLinkedList();
    printReversedLinkedList();
    return 0;
}