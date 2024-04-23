#include <iostream>
using namespace std;

void storeWater(int arr[], int N)
{
    int l = 0, r = N - 1;
    int maxWater = 0;
    int maxHeight = 0;
    // while (l < r)
    // {
    //     minHeight = min(arr[l], arr[r]);
    //     maxWater = max(maxWater, minHeight * (r - l));

    //     if (arr[l] < arr[r])
    //         l++;
    //     else
    //         r--;
    // }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            maxHeight = max(arr[j], arr[i]);
            int minHeigth = min(arr[i], arr[j]);
            maxWater = max(maxWater, minHeigth * (j - i));
            maxWater -= minHeigth;
        }
    }

    cout << maxWater;
}

int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4}; // 10
    int size = sizeof(arr) / sizeof(arr[0]);
    // cout << size;
    storeWater(arr, size);
    return 0;
}