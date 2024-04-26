#include <iostream>
#include <climits>
using namespace std;

class MaxHeap
{
private:
    int *arr;     // Pointer to the array rep heap
    int maxSize;  // max size of the heap
    int heapSize; // current num of ele in heap

    int parent(int i) { return (i - 1) / 2; }
    int lchild(int i) { return 2 * i + 1; }
    int rchild(int i) { return 2 * i + 2; }

    void heapify(int i)
    {
        int l = lchild(i);
        int r = rchild(i);
        int largest = i;
        if (l < heapSize && arr[l] > arr[i])
        {
            largest = l;
        }

        if (r < heapSize && arr[r] > arr[largest])
        {
            largest = r;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap(int maxSize)
    {
        this->maxSize = maxSize;
        heapSize = 0;
        arr = new int[maxSize];
    }

    ~MaxHeap()
    {
        delete[] arr;
    }

    void insert(int key)
    {
        if (heapSize == maxSize)
        {
            cout << " overflown: could not insert" << endl;
            return;
        }

        heapSize++;
        int i = heapSize - 1;
        arr[i] = key;

        while (i > 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int extractMax()
    {
        if (heapSize <= 0)
        {
            return INT_MIN;
        }
        int root = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        heapify(0);
        return root;
    }

    void increaseKey(int i, int newValue)
    {
        arr[i] = newValue;

        while (i > 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        increaseKey(i, INT_MAX);
        extractMax();
    }

    int getMax()
    {
        if (heapSize > 0)
        {
            return arr[0];
        }

        return INT_MIN;
    }

    int size()
    {
        return heapSize;
    }
};

int main()
{
    MaxHeap h(15);

    int keys[] = {3, 10, 12, 8, 2, 14};
    for (int key : keys)
    {
        h.insert(key);
    }

    cout << "Max Element is: " << h.getMax() << endl;
    cout << "Heap Size is: " << h.size() << endl;

    h.deleteKey(14);

    h.insert(10);
    h.insert(5);

    cout << "Max Element is: " << h.getMax() << endl;
    cout << "Heap Size is: " << h.size() << endl;

    return 0;
}