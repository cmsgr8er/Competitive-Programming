// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5;
int N, K;
bool visited[MN];
vector<int> adj[MN];
set<int> cyclic;

void dfs(int node) {
    visited[node] = true;
    for (auto u: adj[node]) {
        if (!visited[u]) dfs(u);
    }
}

int main() {
    cin >> N >> K;
    int a[K], b[K], m, n;
    for (int i=0; i<K; i++) {
        cin >> m >> n >> a[i] >> b[i];
        if (a[i] > b[i]) {
            adj[m-1].push_back(n-1);
        }
        else {
            adj[n-1].push_back(m-1);
        }
    }
    for (int i=0; i<N; i++) {
        visited[i] = false;
    }
    for (int i=0; i<N; i++) {
        for (auto u: adj[i]) {
            dfs(u);
        }
        if (visited[i]) cyclic.insert(i);
        for (int j=0; j<N; j++) {
            visited[j] = false;
        }
    }
    cout << cyclic.size();
}
