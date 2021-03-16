#include <bits/stdc++.h>
using namespace std;

auto find_maximum_score(const vector<int>& cards) -> long long
{
    vector<long long> older(cards.begin(), cards.end());
    vector<long long> old(cards.size());

    for(int i = 0; i + 1 < cards.size(); i++)
        old[i] = max(cards[i], cards[i+1]);

    vector<long long> memo(old.begin(), old.end());

    for(int offset = 2; offset < cards.size(); offset++)
    {
        for(int i = 0; i + offset < cards.size(); i++)
        {
            memo[i] = max((long long)cards[i] + min(older[i+1], older[i+2]), 
                          (long long)cards[i+offset] + min(older[i], older[i+1]));
        }
        copy(old.begin(), old.end(), older.begin());
        copy(memo.begin(), memo.end(), old.begin());
    }

    return memo[0];
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
    //test();
    int N;
    while(cin >> N)
    {
        solve(N);
    }
}
