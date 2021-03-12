#include <bits/stdc++.h>
using namespace std;

auto find_size_of_maximum_palindromic_subsequence_recursive(const string& s, int l, int r) -> int
{
    if(l > r) return 0;
    if(l == r) return 1;
    if(s[l] == s[r]) return 2 + find_size_of_maximum_palindromic_subsequence_recursive(s, l+1, r-1);
    return max(find_size_of_maximum_palindromic_subsequence_recursive(s, l+1, r),
               find_size_of_maximum_palindromic_subsequence_recursive(s, l, r-1));
}

auto find_size_of_maximum_palindromic_subsequence_recursive_memoized(map< pair<int, int>, int>dp, const string& s, int l, int r) -> int
{
    if(dp.count({l, r})) return dp[{l, r}];

    dp[{l, r}] = [&]()
    {
        if(l > r) return 0;
        if(l == r) return 1;
        if(s[l] == s[r]) return 2 + find_size_of_maximum_palindromic_subsequence_recursive(s, l+1, r-1);
        return max(find_size_of_maximum_palindromic_subsequence_recursive(s, l+1, r),
                find_size_of_maximum_palindromic_subsequence_recursive(s, l, r-1));
    }();

    return dp[{l, r}];
}

auto find_size_of_maximum_palindromic_subsequence_iterative(const string& str) -> int
{
    vector<vector<int> > dp(str.size(), vector<int>(str.size()));

    for(unsigned int offset = 0; offset < str.size(); offset++)
        for(unsigned int i = 0; i + offset < str.size(); i++)
            dp[i][i+offset] = [&]()
            {
                if(offset == 0) return 1;
                if(str[i] == str[i+offset]) return 2 + dp[i+1][i+offset-1];
                return max(dp[i+1][i+offset], dp[i][i+offset-1]);
            }();

    return dp[0].back();
}

void simple_example_1()
{
    string s = "turboventilator";
    cout << find_size_of_maximum_palindromic_subsequence_recursive(s, 0, 14) << '\n'; // 7 -> rotator
    map<pair<int, int>, int> dp;
    cout << find_size_of_maximum_palindromic_subsequence_recursive_memoized(dp, s, 0, 14) << '\n';
    cout << find_size_of_maximum_palindromic_subsequence_iterative(s) << '\n';
}

int main()
{
    simple_example_1();
}
