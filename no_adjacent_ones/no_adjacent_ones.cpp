#include <bits/stdc++.h>
using namespace std;

// Given the length of an array n, calculate the number of different arrays
// of length n that only 1's and 0's but do not contain adjacent 1's. 

auto number_of_no_adjacents_ones(int n) -> int
{
    vector<int> dp(n+1);

    dp[0] = 1;
    dp[1] = 2;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

void simple_example_1()
{
    cout << number_of_no_adjacents_ones(2) << '\n'; // 3
    cout << number_of_no_adjacents_ones(3) << '\n'; // 5
    cout << number_of_no_adjacents_ones(4) << '\n'; // 8
}

int main()
{
    simple_example_1();
}
