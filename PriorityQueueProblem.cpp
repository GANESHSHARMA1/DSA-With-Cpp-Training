#include <iostream>
using namespace std;

class Queue
{
public:
    int val;
    Queue *next;
    int difficulty;

    Queue(int data)
    {
        val = data;
        next = nullptr;
        difficulty = INT_MIN;
    }
};

class PriorityQueue
{
private:
    Queue *front;

    void createQueue(Queue *&front, int val, int difficulty)
    {
        Queue *q = new Queue(val);
        q->difficulty = difficulty;
        if (front == nullptr || difficulty <= front->difficulty)
        {
            q->next = front;
            front = q;
        }
        else
        {
            Queue *temp = front;
            while (temp->next != nullptr && temp->next->difficulty > difficulty)
            {
                temp = temp->next;
            }
            if (temp->next == nullptr)
            {
                temp->next = q;
                return;
            }
            q->next = temp->next;
            temp->next = q;
        }
    }

    void pop(Queue *&front)
    {
        if (front == nullptr)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        int data = front->val;
        front = front->next;
        cout << "Solved Problem id is: " << data << endl;
    }
    void peek(Queue *&front)
    {
        if (front == nullptr)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        int data = front->val;
        cout << "Next difficult Problem is: " << data << endl;
    }

public:
    PriorityQueue()
    {
        front = nullptr;
    }

    void addProblem(int id, int difficulty)
    {
        createQueue(front, id, difficulty);
    }

    void solveNextProblem()
    {
        pop(front);
    }

    void peekNextProblem()
    {
        peek(front);
    }
};

int main()
{
    PriorityQueue q;
    q.addProblem(12, 5);
    q.addProblem(10, 2);
    q.addProblem(2, 6);
    q.addProblem(6, 1);
    q.addProblem(7, 7);
    q.peekNextProblem();
    q.solveNextProblem();
    q.solveNextProblem();
    q.solveNextProblem();
    q.solveNextProblem();
    q.solveNextProblem();
    q.solveNextProblem();
    return 0;
}