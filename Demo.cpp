#include <iostream>
#include <climits>
using namespace std;

void findSmallestSumSubarray(int arr[], int n)
{
    int min_sum = INT_MAX;
    int min = INT_MAX;
    int start = 0, end = 0, s = 0;

    for (int i = 0; i < n; i++)
    {
        if (min_sum > 0)
        {
            min_sum = arr[i];
            s = i;
        }
        else
        {
            min_sum += arr[i];
        }

        if (min > min_sum)
        {
            min = min_sum;
            start = s;
            end = i;
        }
    }

    cout << "Smallest sum: " << min << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int arr[] = {2, 6, 8, 1, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    findSmallestSumSubarray(arr, n);

    return 0;
}
