#include <iostream>
using namespace std;

struct item
{
    int value;
    int priority;
};

item arr[100]; // Static Size of array

int size = -1;

// Inserting Element
void enqueue(int value, int priority)
{
    size++;
    arr[size].value = value;
    arr[size].priority = priority;
}

// Top element - Element with highest priority
int peek()
{
    int highestPriority = INT_MIN;
    int idx = -1;
    for (int i = 0; i <= size; i++)
    {
        if (highestPriority == arr[i].priority && idx > -1 && arr[idx].value < arr[i].value)
        {
            highestPriority = arr[i].priority;
            idx = i;
        }
        else if (highestPriority < arr[i].priority)
        {
            highestPriority = arr[i].priority;
            idx = i;
        }
    }
    return idx;
}

void dequeue()
{
    int idx = peek();
    // Shifting the element one index before from the position of the element with the highest priority found
    for (int i = idx; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main()
{
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(15, 3);
    enqueue(12, 5);
    enqueue(17, 5);
    cout << arr[peek()].value << endl;
    dequeue();
    cout << arr[peek()].value << endl;
    return 0;
}