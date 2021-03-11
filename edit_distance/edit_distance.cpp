#include <bits/stdc++.h>
using namespace std;

auto find_minimum_number_of_operations_edit_distance(string s, string t) -> int
{
    vector<vector<int> > dp(s.size()+1, vector<int>(t.size()+1));

    for(int i = 0; i <= s.size(); i++)
    {
        for(int j = 0; j <= t.size(); j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = i + j;
                continue;
            }
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }

    for(const auto&row : dp)
    {
        for(const auto&el : row) cout << el << ' ';
        cout << '\n';
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
