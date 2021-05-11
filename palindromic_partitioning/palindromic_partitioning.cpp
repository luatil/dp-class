#include <bits/stdc++.h>
using namespace std;

const int MAX = 2002;
int palindrome_table[MAX][MAX];
int dp_table[MAX][MAX];

auto is_palindrome(string s, int i, int j) -> bool 
{
    if(palindrome_table[i][j] == -1) 
    {
        palindrome_table[i][j] = [&](){
            if(i == j) return true;
            if(i+1 == j && s[i] == s[j]) return true;
            if(s[i] != s[j]) return false;
            if(s[i] == s[j]) return is_palindrome(s, i+1, j-1);
        }();
    }
    return palindrome_table[i][j];
}

auto dp(string s, int i, int j) -> int 
{
    if(dp_table[i][j] == -1) 
    {
        dp_table[i][j] = [&](){
            if(is_palindrome(s, i, j)) return 1;
            if(i+1==j) return 2;
            int minimun = numeric_limits<int>::max();
            for(int k = i; k < j; k++)
            {
                if(is_palindrome(s, i, k))
                {
                    minimun = min(minimun, 1 + dp(s, k+1, j));
                }
            }
            return minimun;
        }();
    }
    return dp_table[i][j];
} 

auto find_minimum_number_of_palindromic_partitions(string s) -> int
{
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++) 
        {
            palindrome_table[i][j] = -1;
            dp_table[i][j] = -1;
        }

    return dp(s, 0, s.size()-1);
}

void test()
{
    cout << find_minimum_number_of_palindromic_partitions("aaxyx") << '\n'; // 2
    cout << find_minimum_number_of_palindromic_partitions("axa") << '\n'; // 1
    cout << find_minimum_number_of_palindromic_partitions("xyzyyx") << '\n'; // 4
    cout << find_minimum_number_of_palindromic_partitions("bbabcbbaab") << '\n'; // 4
}

int main()
{
    test();
}