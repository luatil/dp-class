#include <bits/stdc++.h>
using namespace std;

// You need to traverse a staircase, but each step costs something, 
// find the minimum cost you need to traverse it if you can only 
// go to steps n+1 and n+2 from step n.

auto find_minimun_cost_to_traverse_staircase(const vector<int>& staircase) -> int
{
    vector<int> dp(staircase.size());

    dp[0] = 0;
    dp[1] = staircase[1];

    for(int i = 2; i < staircase.size(); i++)
        dp[i] = staircase[i] + min(dp[i-1], dp[i-2]);

    return dp.back();
}

auto find_minimun_cost_to_traverse_staircase_forward_dp(const vector<int>& staircase) -> int
{
    vector<int> dp(staircase.size());

    dp[0] = 0;
    dp[1] = staircase[1];

    for(int i = 0; i < staircase.size()-2; i++)
        dp[i+2] = staircase[i] + min(dp[i], dp[i+1]);

    return dp.back();
}


auto find_minimun_cost_to_traverse_staircase_constant_space(const vector<int>& staircase) -> int
{
    int a = 0, b = staircase[1], c = 0;

    for(int i = 2; i < staircase.size(); i++)
    {
        c = staircase[i] + min(a, b);
        a = b;
        b = c;
    }

    return c;
}

// Time complexity of staircase.size() * k
auto find_minimum_cost_to_traverse_staircase_k_steps(const vector<int> & staircase, int k) -> int
{
    vector<int> dp(staircase.size());
    dp[0] = 0;

    for(int i = 1; i < staircase.size(); i++)
    {
        dp[i] = staircase[i] + *min_element(dp.begin() + max(i - k, 0), dp.begin() + i);
    }

    return dp.back();
}

// There is a way to calculate minimum cost to traverse staircase with k steps in staircase.size() time complexity
// this uses a rolling window technique


void simple_example_1()
{
    vector<int> v = {0, 3, 5, 6, 7, 1, 5, 4, 3, 0};
    cout << find_minimun_cost_to_traverse_staircase(v) << '\n';
    cout << find_minimun_cost_to_traverse_staircase_forward_dp(v) << '\n';
    cout << find_minimun_cost_to_traverse_staircase_constant_space(v) << '\n';
}

void simple_example_2()
{
    vector<int> v = {0, 3, 5, 6, 7, 1, 5, 4, 3, 0};
    cout << find_minimum_cost_to_traverse_staircase_k_steps(v, 2) << '\n';
    cout << find_minimum_cost_to_traverse_staircase_k_steps(v, 3) << '\n';
}

auto find_minimum_cost_path_to_traverse_staircase_with_two_steps(const vector<int>& staircase) -> vector<int>
{
    vector<int> dp(staircase.size());
    vector<int> parent(staircase.size());

    dp[0] = 0;
    dp[1] = staircase[1];

    for(int i = 2; i < staircase.size(); i++)
    {
        dp[i] = staircase[i];
        if(dp[i-1] < dp[i-2])
        {
            dp[i] += dp[i-1];
            parent[i] = i-1;
        }
        else 
        {
            dp[i] += dp[i-2];
            parent[i] = i-2;
        }
    }

    int i = staircase.size() - 1;
    vector<int> minimum_cost_path;
    while(i != 0)
    {
        minimum_cost_path.push_back(i);
        i = parent[i];
    }

    reverse(minimum_cost_path.begin(), minimum_cost_path.end());
    return minimum_cost_path;
}

auto find_minimum_cost_path_to_traverse_staircase_with_k_steps(const vector<int>& staircase, int k) -> vector<int>
{
    vector<int> dp(staircase.size());
    vector<int> parent(staircase.size());

    constexpr int inf = numeric_limits<int>::max();
    dp[0] = 0;

    for(int i = 1; i < staircase.size(); i++)
    {
        dp[i] = inf;
        for(int j = 1; j <= k; j++)
        {
            if(i-j >= 0)
            {
                if(dp[i-j] + staircase[i] < dp[i])
                {
                    dp[i] = dp[i-j] + staircase[i];
                    parent[i] = i-j;
                }
            }
        }
    }

    int i = staircase.size() - 1;
    vector<int> minimum_cost_path;
    while( i != 0)
    {
        minimum_cost_path.push_back(i);
        i = parent[i];
    }

    reverse(minimum_cost_path.begin(), minimum_cost_path.end());
    return minimum_cost_path;
}

auto find_minimum_cost_path_to_traverse_staircase_with_k_steps_ver_2(const vector<int>& staircase, int k) -> vector<int>
{
    vector<int> dp(staircase.size());
    vector<int> parent(staircase.size());

    dp[0] = 0;

    for(int i = 1; i < staircase.size(); i++)
    {
        auto it = min_element(dp.begin() + max(i-k, 0), dp.begin() + i); // exclusive on the end of the range
        dp[i] = staircase[i] + *it;
        parent[i] = distance(dp.begin(), it);
    }

    int i = staircase.size() - 1;
    vector<int> minimum_cost_path;
    while(i != 0)
    {
        minimum_cost_path.push_back(i);
        i = parent[i];
    }

    reverse(minimum_cost_path.begin(), minimum_cost_path.end());
    return minimum_cost_path;
}

void simple_example_3()
{
    vector<int> v = {0, 3, 5, 6, 7, 1, 5, 4, 3, 0};
    vector<int> minimum_cost_path = find_minimum_cost_path_to_traverse_staircase_with_two_steps(v);
    for(const auto&el : minimum_cost_path) cout << el << ' ';
    cout << '\n';
}

void simple_example_4()
{
    vector<int> v = {0, 3, 2, 6, 7, 1, 5, 4, 3, 0};
    vector<int> minimum_cost_path = find_minimum_cost_path_to_traverse_staircase_with_k_steps(v, 2);
    vector<int> minimum_cost_path_2 = find_minimum_cost_path_to_traverse_staircase_with_k_steps_ver_2(v, 2);
    for(const auto&el : minimum_cost_path) cout << el << ' ';
    cout << '\n';
    for(const auto&el : minimum_cost_path_2) cout << el << ' ';
    cout << '\n';
}

void simple_example_5()
{
    vector<int> v = {0, 3, 2, 6, 7, 1, 5, 4, 3, 0};
    vector<int> minimum_cost_path = find_minimum_cost_path_to_traverse_staircase_with_k_steps(v, 3);
    vector<int> minimum_cost_path_2 = find_minimum_cost_path_to_traverse_staircase_with_k_steps_ver_2(v, 3);
    for(const auto&el : minimum_cost_path) cout << el << ' ';
    cout << '\n';
    for(const auto&el : minimum_cost_path_2) cout << el << ' ';
    cout << '\n';
}

int main()
{
    simple_example_4();
    simple_example_5();
}
