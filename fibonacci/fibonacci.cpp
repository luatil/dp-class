#include <bits/stdc++.h>
using namespace std;

auto fib(vector<int>& memo, int n) -> int
{
    if(memo[n] == -1) memo[n] = fib(memo, n-1) + fib(memo, n-2);
    return memo[n];
}

void simple_example_1()
{
    const unsigned int MAX = 100;
    vector<int> memo(MAX, -1);
    memo[1] = 1;
    memo[2] = 1;
    cout << "fib(5): " << fib(memo, 5) << '\n';
    cout << "fib(8): " << fib(memo, 8) << '\n';
    cout << "fib(20): " << fib(memo, 20) << '\n';
}

int main()
{
    simple_example_1();
}
