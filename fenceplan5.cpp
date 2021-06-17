// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 10;
int N, M, xmax =0 , xmin = 1e9, ymax =0, ymin = 1e9, x[MN], y[MN], 
perimeter = 1e9, length, height, answer = 1e9;
bool visited[MN];
vector<int> adj[MN];

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    xmin = min(xmin, x[node]);
    xmax = max(xmax, x[node]);
    ymin = min(ymin, y[node]);
    ymax = max(ymax, y[node]);
    length = xmax - xmin;
    height = ymax - ymin;
    for (auto u: adj[node]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}


void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("fenceplan");
    cin >> N >> M;
    int a, b;
    for (int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
        visited[i] = false;
    }
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for (int i=0; i<N; i++) {
        dfs(i);
        perimeter = 2*(length + height);
        answer = min(answer, perimeter);
        xmax =0;
        xmin = 1e9; 
        ymax =0;
        ymin = 1e9;
    }
    cout << answer;
}
