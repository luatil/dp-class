#include <bits/stdc++.h>
using namespace std;

// Count the number of ways you can go up a staircase with N steps if 
// you can go from to step x to step x+1, x+2, ... x + K.

auto number_of_ways_to_climb(int N, int K)
{
    // vector<vector<int> > dp(N, vector<int>(K));
    vector<int> dp(N+1);

    dp[0] = 1;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            if(i-j >= 0) dp[i] += dp[i-j];
        }
    }

    return dp[N];
}

void test1()
{
    cout << number_of_ways_to_climb(3, 3) << '\n'; // 4
    cout << number_of_ways_to_climb(4, 3) << '\n'; // 7
}

int main()
{
    test1();
}