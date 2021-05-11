#include <bits/stdc++.h>
using namespace std;

int memo[20];

int dp(int n) {
    if(memo[n] != -1) return memo[n];
    if(n == 0 || n == 1) return 1;
    return dp(n-1) + dp(n-2);
}

int main()
{
    memset(memo, memo, -1);
    cout << dp(20) << '\n';
}
