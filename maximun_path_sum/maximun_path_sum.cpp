#include <bits/stdc++.h>
using namespace std;

// Given a grid, find a path from the top left to the
// bottom right corner that minimizes the sum of numbers
// along the path. You can only move right or down.

auto maximum_path_sum(vector<vector<int> > grid) -> int
{
    int N = grid.size();
    int M = grid[0].size();

    vector<vector<int> > dp(N, vector<int>(M, 0));

    dp[0][0] = grid[0][0];

    for(int i = 1; i < N; i++)
        dp[i][0] += dp[i-1][0] + grid[i][0];

    for(int i = 1; i < M; i++)
        dp[0][i] += dp[0][i-1] + grid[0][i];

    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j < M; j++)
        {
            dp[i][j] = min( dp[i-1][j], dp[i][j-1] ) + grid[i][j];
        }
    }

    return dp[N-1][M-1];
}

void simple_example_1()
{
    vector<vector<int> > v = {{3, 2, 1, 3}, {1, 9, 2, 3}, {9, 1, 5, 4}};
    cout << maximum_path_sum(v) << '\n';
}

int main()
{
    simple_example_1();
}
