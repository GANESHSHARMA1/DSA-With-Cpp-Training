#include <iostream>
using namespace std;

int minJumps(int arr[], int N)
{
    if (N <= 1)
        return 0;

    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 1;

    for (int i = 1; i < N; ++i)
    {
        if (i == N - 1)
            return jumps;

        maxReach = max(maxReach, i + arr[i]);

        steps--;

        if (steps == 0)
        {
            jumps++;
            if (i >= maxReach)
                return -1;
            steps = maxReach - i;
        }
    }

    return jumps;
}

int main()
{
    int N = 13;
    int arr[] = {1, 5, 2, 7, 5, 6, 3, 7, 8, 3, 8, 3, 7};
    cout << "Minimum number of jumps: " << minJumps(arr, N) << endl;
    return 0;
}
