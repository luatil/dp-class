#include <bits/stdc++.h>
using namespace std;

auto find_minimum_number_of_operations_edit_distance(string s, string t) -> int
{
    vector<vector<int> > dp(s.size()+1, vector<int>(t.size()+1));

    for(int i = 0; i <= s.size(); i++)
    {
        for(int j = 0; j <= t.size(); j++)
        {
            dp[i][j] = [&]() {
                if(i == 0 || j == 0)  return i + j;
                if(s[i-1] == t[j-1])  return dp[i-1][j-1];
                return 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }();
        }
    }

    return dp.back().back();
}

void simple_example_1()
{
    string s = "apple";
    string t = "alpine";

    // 1) Change letter 
    // 2) Add letter
    // 3) Remove letter

    cout << find_minimum_number_of_operations_edit_distance(s, t) << '\n'; // 3
}

int main()
{
    simple_example_1();
}
