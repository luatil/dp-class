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

auto number_of_ways_to_climb_linear(int N, int K)
{
    // vector<vector<int> > dp(N, vector<int>(K));
    vector<int> dp(N+1);
    vector<int> prefix(N+1);

    dp[0] = 1;
    prefix[0] = 1;

    for(int i = 1; i < K; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            dp[i] += (i-j >= 0)*dp[i-j];
            prefix[i] = dp[i] + prefix[i-1];
        }
    }

    for(int i = K; i <= N; i++)
    {
        dp[i] = 1 + prefix[i-1] - prefix[i-K];
        prefix[i] = dp[i] + prefix[i-1];
    }

    return dp[N];
}


void test1()
{
    cout << number_of_ways_to_climb(3, 3) << '\n'; // 4
    cout << number_of_ways_to_climb(4, 3) << '\n'; // 7
}

void test2()
{
    cout << number_of_ways_to_climb_linear(3, 3) << '\n'; // 4
    cout << number_of_ways_to_climb_linear(4, 3) << '\n'; // 7
}

int main()
{
    test1();
    test2();
}