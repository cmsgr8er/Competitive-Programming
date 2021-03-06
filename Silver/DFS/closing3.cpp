// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;



const int MN = 1e5 + 10;
int N, M;
vector<int> adj[MN];
bool closed[MN];
bool visited[MN];

void dfs(int s) {
    visited[s] = true;
    for (auto u: adj[s]) {
        if (!visited[u] && !closed[u]) {
            dfs(u);
        }
    }
}

int components() {
    int count = 0;
    for (int i=1; i<=N; i++) {
        if (!visited[i] && !closed[i]) {
            count++;
            dfs(i);
        }
    }
    return count;
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("closing");
    cin >> N >> M;
    int a,b;
    int remove[N];
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<N; i++) {
        cin >> remove[i];
    }

    for (int i=1; i<=N; i++) {
        closed[i] = false;
    }

    for (int i=0; i<N; i++) {
        for (int t =1; t<=N; t++) {
            visited[t] = false;
        }
        if (components() <= 1) cout << "YES" << endl;
        else cout << "NO" << endl;
        closed[remove[i]] = true;
    }
}
