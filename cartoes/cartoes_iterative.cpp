#include <bits/stdc++.h>
using namespace std;


auto find_maximum_score(const vector<int>& cards) -> long long
{
    vector<vector<long long> > memo(cards.size(), vector<long long>(cards.size(), -1));

    for(int offset = 0; offset <= cards.size(); offset++)
    {
        for(int i = 0; i + offset < cards.size(); i++)
        {
            memo[i][i+offset] = [&]()
            {
                if(offset == 0) return (long long)cards[i];
                if(offset == 1) return (long long)max(cards[i], cards[i+offset]);
                return max((long long)cards[i] + min(memo[i+2][i+offset], memo[i+1][i+offset-1]), 
                           (long long)cards[i+offset] + min(memo[i][i+offset-2], memo[i+1][i+offset-1]));
            }();
        }
    }

    return memo[0][cards.size()-1];
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
