#include <bits/stdc++.h>
using namespace std;

// You are given a sequence of coins, and a target value. You need to find the minimum number 
// of coins that add up to the target value. And you can only use a coin once. Return -1 if 
// the sum is impossible.

auto find_minimum_number_of_coins_to_make_change(const vector<int>& coins, const int& target) -> int
{
    const int larger_coin = *max_element(coins.cbegin(), coins.cend());
    constexpr int inf = numeric_limits<int>::max() - 1000;
    // memo[i] means the minimum number of coins to make the value of i
    vector<int> memo(target + 1 + larger_coin, inf);

    memo[0] = 0;

    for(int i = 0; i < coins.size(); i++)
        for(int j = target; j >= 0; j--)
            memo[j+coins[i]] = min(1 + memo[j], memo[j+coins[i]]);

    return (memo[target] == inf ? -1 : memo[target]);
}

void simple_example_1()
{
    vector<int> coins = {1, 2, 2, 2, 5};
    int target = 6; 
    cout << find_minimum_number_of_coins_to_make_change(coins, target) << '\n'; // 2 -> 1, 5
}

int main()
{
    simple_example_1();
}