#include <bits/stdc++.h>
using namespace std;

const int MAX = 3'003;
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
    return 2 * dp(cards, 0, cards.size()-1) - accumulate(cards.cbegin(), cards.cend(), 0LL);
}

void test()
{
    vector<int> t1 = {10, 80, 90, 30};
    cout << find_maximum_score(t1) << '\n'; // 10
    vector<int> t2 = {10, 100, 10};
    cout << find_maximum_score(t2) << '\n'; // -80
    vector<int> t3 = {4, 2, 9, 7, 1, 5};
    cout << find_maximum_score(t3) << '\n'; // 2
    vector<int> t4 = {1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1};
    cout << find_maximum_score(t4) << '\n'; // 4999999995
}

void solve()
{
    int N; cin >> N;
    vector<int> cards(N);
    for(auto&el : cards) cin >> el;

    cout << find_maximum_score(cards) << '\n';
}

int main()
{
    //solve();
    test();
}
