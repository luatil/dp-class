#include <bits/stdc++.h>
using namespace std;

const int inf = numeric_limits<int>::max() / 2;

auto badness(const vector<string>& words, int page_width, int i, int j) -> int
{
    const int line_size = accumulate(words.cbegin()+i, words.cbegin()+j+1, -1, [](int total, string word){ return total + word.size()+1;});
    if(line_size > page_width) return inf; 
    return pow(page_width - line_size, 3);
}

int find_minimum_badness_suffix_iterative(const vector<string>& words, int page_width)
{
    vector<int> memo(words.size(), inf);

    memo.push_back(0);

    for(int i = memo.size()-2; i >= 0; --i)
    {
        for(int j = 0; j + i + 1 < memo.size(); ++j)
        {
            memo[i] = min(memo[i], memo[i+j+1] + badness(words, page_width, i, i+j));
        }
    }

    return memo.front();
}

int find_minimum_badness_prefix_iterative(const vector<string>& words, int page_width)
{
    vector<int> memo(words.size()+1, inf);

    memo[0] = 0;

    for(int i = 1; i < memo.size(); i++)
    {
        for(int j = 0; (i - j) -1 >= 0; j++)
        {
            memo[i] = min(memo[i], memo[(i-j)-1] + badness(words, page_width, (i-j)-1, i-1));
        }
    }

    return memo.back();
}

void test1()
{ 
    vector<string> t1 = {"Hello", "this", "is", "a", "test"}; 
    cout << badness(t1, 80, 0, 4) << '\n';
    cout << find_minimum_badness_suffix_iterative(t1, 80) << '\n'; 
    cout << find_minimum_badness_prefix_iterative(t1, 80) << '\n'; 
    // They should be equal
}

void test2()
{ 
    vector<string> t1 = {"Hello", "this", "is", "a", "test"}; 
    cout << badness(t1, 10, 0, 1) + badness(t1, 10, 2, 4) << '\n';
    cout << find_minimum_badness_suffix_iterative(t1, 10) << '\n';
    cout << find_minimum_badness_prefix_iterative(t1, 10) << '\n';
    // They should be equal
}

int main()
{
    test1();
    test2();
}
