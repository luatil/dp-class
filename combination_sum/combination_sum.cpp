#include <bits/stdc++.h>
using namespace std;

// Combination Sum 
// 
// Given the target value N and an array of allowed numbers,
// count way to write N as the sum of those numbers.

// forward version
auto combination_sum(vector<int> arr, int target) -> int
{
    vector<int> dp(target+*max_element(arr.begin(), arr.end())+1);
    
    dp[0] = 1;

    for(int i = 0; i <= target; i++)
        for(const auto&el : arr)
            dp[i+el] += dp[i];

    return dp[target];
}

auto backward_combination_sum(vector<int> arr, int target) -> int
{
    vector<int> dp(target+1);
    
    dp[0] = 1;

    for(int i = 1; i <= target; i++)
    {
        for(const auto&el : arr)
            // dp[i] += dp[i-el*(el<=i)]*(el<=i);
            dp[i] += (el<=i)*dp[i-el]; // compiler dependent
    }

    return dp[target];
}

void simple_example_1()
{
    vector<int> v = {1, 2, 3};
    int target = 4;
    // 1 + 1 + 1 + 1
    // 1 + 1 + 2
    // 1 + 2 + 1
    // 1 + 3
    // 2 + 1 + 1
    // 2 + 2
    // 3 + 1
    // total = 7
    cout << backward_combination_sum(v, target) << '\n'; 
}

int main()
{
    simple_example_1();
}
