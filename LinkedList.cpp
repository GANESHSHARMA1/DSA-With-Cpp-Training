#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *head = NULL;
Node *tail = NULL;
int size = 0;
void insertAtHead(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
        size++;
        return;
    }
    newNode->next = head;
    head = newNode;
    size++;
}

void insertAtLast(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
        size++;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    size++;
}

void printLinkedList()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty." << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    // cout << "Tail data is : " << tail->data << endl;
    // cout << "The lenght of Linked List is : " << size << endl;
}

void insertAtPos(int data, int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "This position doesn't exist in Linked List" << endl;
        return;
    }
    if (pos == 1)
    {
        insertAtHead(data);
        return;
    }
    Node *temp = head;
    Node *newNode = new Node(data);
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            insertAtLast(data);
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
    delete temp;
}

int deleteAtHead()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty!.";
        return -1;
    }
    Node *temp = head;
    int data = head->data;
    temp = temp->next;
    head = temp;
    size--;
    return data;
}

int deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty!.";
        return -1;
    }
    if (head->next == nullptr)
    {
        head = tail = nullptr;
        return -1;
    }
    Node *temp = head;
    Node *temp1 = NULL;
    int data = tail->data;
    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    tail = temp1;
    size--;
    return data;
}

int deleteAtPos(int pos)
{
    if (pos < 1 || pos >= size)
    {
        cout << "This position doesn't exist in Linked List" << endl;
        return -1;
    }
    if (head == NULL)
    {
        cout << "Linked List is Empty!.";
        return -1;
    }
    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    int data = temp->next->data;
    temp->next = temp->next->next;
    size--;
    return data;
}

void deleteByValue(int value)
{
    Node *temp = head;
    int idx = 0;
    if (head == NULL)
    {
        cout << "Linked List is Empty." << endl;
        return;
    }
    if (value == head->data)
    {
        deleteAtHead();
        return;
    }
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            deleteAtPos(idx);
            return;
        }
        idx++;
        temp = temp->next;
    }
    cout << "This Value is not Present in the Linked List" << endl;
    delete temp;
}

void TestLinkedList()
{
    int choice = 0, pos = 0, data = 0, value = 0;
    do
    {
        cout << "Enter :- " << endl;
        cout << "1. Enter At the Begining " << endl;
        cout << "2. Enter At the End " << endl;
        cout << "3. Enter At the Position " << endl;
        cout << "4. Delete from the Begining " << endl;
        cout << "5. Delete from the End " << endl;
        cout << "6. Delete At the position " << endl;
        cout << "7. Delete Node By Value " << endl;
        cout << "8. Display the Linked List" << endl;
        cout << "9. Enter -1 to Exit." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Data : " << endl;
            cin >> data;
            insertAtHead(data);
            break;
        case 2:
            cout << "Enter Data : " << endl;
            cin >> data;
            insertAtLast(data);
            break;
        case 3:
            cout << "Enter Data : " << endl;
            cin >> data;
            cout << "Enter the Position : " << endl;
            cin >> pos;
            insertAtPos(data, pos);
            break;
        case 4:
            deleteAtHead();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            cout << "Enter the Position : " << endl;
            cin >> pos;
            deleteAtPos(pos);
            break;
        case 7:
            cout << "Enter Value : " << endl;
            cin >> value;
            deleteByValue(value);
            break;
        case 8:
            printLinkedList();
            break;
        case 9:
            exit(1);
            break;
        default:
            cout << "Choose Appropraite Value" << endl;
            break;
        }
    } while (choice != -1);
}

int main()
{
    TestLinkedList();
    // insertAtHead(30);
    // insertAtHead(20);
    // insertAtHead(10);
    // insertAtLast(40);
    // insertAtLast(50);
    // printLinkedList();
    // insertAtPos(25, 2);
    // printLinkedList();
    // insertAtPos(5, 1);
    // printLinkedList();
    // insertAtPos(60, 7);
    // printLinkedList();
    // cout << "Data Deleted is: " << deleteAtHead() << endl;
    // printLinkedList();
    // cout << "Data Deleted is: " << deleteAtEnd() << endl;
    // printLinkedList();
    // cout << "Data Deleted is: " << deleteAtPos(6) << endl;
    // printLinkedList();
    return 0;
}