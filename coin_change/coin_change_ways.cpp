#include <bits/stdc++.h>
using namespace std;

// Coin change (ways)
// 
// You are given denominations of coins and the target amount N.
// What is the number of ways to make up amount N?

// forward version
auto min_coin_change(vector<int> coins, int target) -> int
{
    vector<int> dp(target+*max_element(coins.begin(), coins.end())+1, 1e9);
    
    dp[0] = 0;

    for(int i = 0; i <= target; i++)
        for(const auto&el : coins)
            dp[i+el] = min(dp[i+el], dp[i]+1);

    return dp[target];
}


void simple_example_1()
{
    vector<int> v{1, 2, 5};
    int n = 11;
    cout << min_coin_change(v, n) << '\n';
}

int main()
{
    simple_example_1();
}
