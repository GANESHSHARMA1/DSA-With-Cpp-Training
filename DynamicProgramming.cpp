// Dynamic Programming :-
// Quote :- '''Those who forgets the past are condemned to repeat it'''
/*
'''Approach
    (1) Top to Bottom (Memoization)
        Example :- Fibonacci Problem using DP
    (2) Bottom Up (Tabulation)
    (3) Space Optimization
'''

'''DP is Applied is used when we can solve bigger problem using the optimal solution of a smaller overlap sub-problem'''

*/
/*
    Memoization
    --> 1) DP Array
    --> 2) Store Values
*/

/*
    Tabulation
    --> 1) Create DP Array
*/

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int fib(int n, vector<int> dp)
{
    // Base Case
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    // Step - 2
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    // Memoization (T -> O(n), S -> O(n)) -> Step - 1
    // vector<int> dp(n + 1, -1);
    // int ans = fib(n, dp);
    // int ans = fib(n, dp);
    // cout << ans;

    // Tabulation(T -> O(n), S -> O(1)) -> Step - 1
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;
    return 0;
}
