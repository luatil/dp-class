#include <bits/stdc++.h>
using namespace std;

// dp(i, j, k) = max(a[i] + dp(i+1, j, 1), a[j] + dp(i+1, j, 1)) if k = 0
// dp(i, j, k) = min (dp(i+1, j, 0), dp(i+1, j, 0)) if k = 1 

const int MAX = 10'004;
long long memo[MAX][MAX];

auto dp(const vector<int>& cards, int l, int r) -> long long
{
    if(l > r) return 0;
    if(l == r) return cards[l];

    if(memo[l][r] == -1)
    {
        memo[l][r] = max(cards[l] + min(dp(cards, l+2, r), dp(cards, l+1, r-1)), 
                         cards[r] + min(dp(cards, l, r-2), dp(cards, l+1, r-1)));
    }

    return memo[l][r];
}

auto find_maximum_score(const vector<int>& cards) -> long long
{
    for(int i = 0; i < cards.size(); i++)
    {
        for(int j = 0; j < cards.size(); j++)
        {
            memo[i][j] = -1;
        }
    }
    return dp(cards, 0, cards.size()-1);
}

void test()
{
    vector<int> t1 = {0, -3, 5, 10};
    cout << find_maximum_score(t1) << '\n';
    vector<int> t2 = {0, -3, 5, 7};
    cout << find_maximum_score(t2) << '\n';
    vector<int> t3 = {47, 50, -3, 7};
    cout << find_maximum_score(t3) << '\n';
}

void solve(int N)
{
    vector<int> cards(N);
    for(auto&el : cards) cin >> el;

    cout << find_maximum_score(cards) << '\n';
}

int main()
{
    int N;
    while(cin >> N)
    {
        solve(N);
    }
}
