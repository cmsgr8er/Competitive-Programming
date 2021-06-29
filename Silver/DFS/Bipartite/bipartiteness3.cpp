#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 10;
bool visited[MN];
vector<int> adj[MN], one, two;
int team[MN] = {0};

void dfs(int node) {
    visited[node] = true;
    for (auto u: adj[node]) {
        if (!visited[u]) {
            team[u] = 3-team[node];
            if (team[u] == 1) one.push_back(u);
            if (team[u] == 2) two.push_back(u);
            dfs(u);
        }
    }
}

int main() {
    int n, a, b, answer;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    team[1] = 1;
    one.push_back(1);
    dfs(1);
    cout << one.size()*two.size() - n + 1;
}