#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> is_palindrome;
    vector<vector<int>> memo;

    vector<vector<int>> get_palindromic_table(string s)
    {
        vector<vector<int>> palindromic_table(s.size(), vector<int>(s.size()));
        for(int offset = 0; offset < s.size(); offset++)
        {
            for(int i = 0; i + offset < s.size(); i++)
            {
                palindromic_table[i][i+offset] = [&](){
                    if(offset == 0) return 1;
                    if(offset == 1) return (int)(s[i] == s[i+offset]);
                    if(s[i] == s[i+offset]) return palindromic_table[i+1][i+offset-1];
                    return 0;
                }();
            }
        }
        return palindromic_table;
    }
    
    void print(vector<vector<int>> table)
    {
        for(auto&row : table) 
        {
            for(auto&el : row)
                cout << el << ' ';
            cout << '\n';
        }
    }

    
    int minCut(string s) 
    {
        is_palindrome = get_palindromic_table(s);
        fill_n(back_inserter(memo), s.size(), vector<int>(s.size(), -1));

        for(int offset = 0; offset < s.size(); offset++)
        {
            for(int i = 0; i + offset < s.size(); i++)
            {
                int j = i+offset;
                memo[i][j] = [&](){
                    if(is_palindrome[i][j] == 1) return 0;
                    if(i+1==j) return 1;
                    int minimum = 3000;
                    for(int k = i; k < j; k++)
                    {
                        minimum = min(minimum, memo[i][k] + memo[k+1][j] + 1);
                    }
                    return minimum;
                }();
            }
        }
        //print(memo);
        return memo[0].back();
    }
};

int main()
{
    Solution s1;
    cout << s1.minCut("aaxyx") << '\n';
}