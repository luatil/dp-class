#include <bits/stdc++.h>
using namespace std;

// Count the total number of ways you can climb a staircase of N steps if you can go from step i to step i+1 or step i+2

const int N = 100;
vector<int> adj[N];
int state[N];
int ways[N];
vector<int> topological_order;

void dfs(int i) {
    if(!state[i]) {
        state[i] = 1; // This works for cycle detection
        for_each(adj[i].begin(), adj[i].end(), dfs);
    }
    if(state[i] != 2) {
        state[i] = 2;
        topological_order.push_back(i);
    }
}

int main()
{
    int n; cin >> n;
    for(int i = 0; i <= n; i++)
    {
        // Here is the advantage of this approach, you can change this without the rest of the problem.
        // This even allows for different climbs given a step.  
        // You could think of each step having a trampoline of strength K. That would allow you to jump to steps in 
        // the range i+1 to i+K. And you would just need to change this here. 
        adj[i].push_back(i + 1);
        adj[i].push_back(i + 2);
        adj[i].push_back(i + 3);
    }

    memset(state, 0, sizeof(state));
    memset(ways, 0, sizeof(ways));
    for(int i = 0; i <= n; i++) dfs(i);
    reverse(topological_order.begin(), topological_order.end());    
    for(auto&el : topological_order) cout << el << ' ';
    cout << '\n';

    ways[topological_order[0]] = 1;

    for(int i = 0; i <= n; i++) {
        for(auto &el : adj[topological_order[i]]) {
            ways[topological_order[el]] += ways[topological_order[i]];
        }
    }

    cout << ways[n] << '\n';
}