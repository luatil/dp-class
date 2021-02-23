#include <bits/stdc++.h>
using namespace std;

// Use stairs problem to introduce the class to DP.  You are
// climbing a staircase. It takes N steps to reach to the
// top. Each time you either climb 1 or 2 steps.  In how many
// distinct ways can you climb to the top?

auto number_of_ways_to_climb_staircase(int number_of_steps) -> int
{
    int total_number_of_ways = 0; 

    int first_way = 1, second_way = 1;

    for(int i = 0; i < number_of_steps; i++)
    {
        total_number_of_ways += second_way + first_way;
        first_way = second_way;
        second_way = total_number_of_ways;
    }

    return total_number_of_ways;
}

auto total_limited_ways(int steps, int max_steps) -> int
{
    int dp[steps][max_steps] = {0};

    for(int i = 0; i < max_steps; i++)
        dp[0][i] = 1;

    for(int i = 1; i < max_steps; i++)
        dp[1][i] = 1;

    for(int i = 2; i < steps; i++)
    {
        for(int k = 1; k < max_steps; k++)
            dp[i][k] = dp[i-1][k-1] + dp[i-2][k-1];
    }

    return (steps >= 1 && max_steps >= 1 ? dp[steps-1][max_steps-1] : -1);
}

void simple_example_1()
{
    cout << "5:4 " << total_limited_ways(5, 4) << '\n';
    cout << "5:5 " << total_limited_ways(5, 5) << '\n';
    cout << "7:7 " << total_limited_ways(7, 7) << '\n';
}

int main()
{
    simple_example_1();
}
