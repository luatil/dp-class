#include <bits/stdc++.h>
using namespace std;

// Coin change (min)
// 
// You are given denominations of coins and the target amount N.
// What is the minimum possible number of coins used?

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

constexpr int max_value = numeric_limits<int>::max() -1000;

auto find_min_coin_change_recursive(const vector<int> & coins, const int& target) -> int
{
    if(target == 0) return 0;
    if(target < 0) return max_value;

    int minimum = max_value;
    for(const auto& el : coins)
    {
        minimum = min(minimum, find_min_coin_change_recursive(coins, target - el) + 1);
    }
    return minimum;
}

auto find_min_coin_change_recursive_memoized(vector<int>& memo, const vector<int>& coins, const int& target) -> int
{
    if(target == 0) return 0;
    if(target < 0) return max_value;

    if(memo[target] == -1)
    {
        int minimum = max_value;
        for(const auto& el : coins)
        {
            minimum = min(minimum, find_min_coin_change_recursive_memoized(memo, coins, target - el) + 1); // coins cannot have a negative value otherwise we never halt 
        }
        memo[target] = minimum;
    }
    return memo[target];
}

auto find_min_coin_change_recursive_memoized_ver2(vector<vector<int>>& memo, const vector<int>& coins, const int& target, const int& index) -> int
{
    if(target < 0 || index >= coins.size()) return max_value;
    if(target == 0) return 0;

    if(memo[index][target] == -1)
    {
        memo[index][target] = min(1 + find_min_coin_change_recursive_memoized_ver2(memo, coins, target - coins[index], index), 
                                      find_min_coin_change_recursive_memoized_ver2(memo, coins, target, index+1));
    }
    return memo[index][target];
}

auto find_min_coin_change_iterative_ver2(vector<vector<int>>& memo, const vector<int>& coins, const int& target, const int& index) -> int;

void simple_example_1()
{
    vector<int> v{1, 2, 5};
    int target = 11;
    cout << min_coin_change(v, target) << '\n'; // 3 -> 2 * 5 + 1
    cout << find_min_coin_change_recursive(v, target) << '\n'; // 3 -> 2 * 5 + 1
    vector<int> memo(target+1, -1);
    cout << find_min_coin_change_recursive_memoized(memo, v, target) << '\n'; // 3 -> 2 * 5 + 1
    vector<vector<int>> memo2(v.size(), vector<int>(target+1, -1));
    cout << find_min_coin_change_recursive_memoized_ver2(memo2, v, target, 0) << '\n';
}

int main()
{
    simple_example_1();
}
