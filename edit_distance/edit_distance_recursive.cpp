#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int memo[505][505];
    
    int dp(const string& s, const string&t, int i, int j)
    {  
        return memo[i][j] = [&]() {
            if(memo[i][j] != -1) return memo[i][j];
            if(i == 0 || j == 0) return i + j;
            if(s[i-1] == t[j-1]) return dp(s, t, i-1, j-1);
            return 1 + min({dp(s, t, i-1, j), dp(s, t, i, j-1), dp(s, t, i-1, j-1)});
        }();
    }
    
    
    int minDistance(string word1, string word2) {
        memset(memo, -1, sizeof(memo));
        return dp(word1, word2, word1.size(), word2.size());
    }
};