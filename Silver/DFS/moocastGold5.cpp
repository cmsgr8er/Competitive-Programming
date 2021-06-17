// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 10;
int N, counter, x[MN], y[MN];
bool visited[MN];
vector<int> adj[MN];

void dfs(int node) {
    visited[node] = true;
    for (auto u: adj[node]) {
        if (!visited[u]) {
            counter++;
            dfs(u);
        }
    }
}

bool isConnected(int distance) {
    counter = 1;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if((x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i])<= distance) {
                adj[j].push_back(i);
                adj[i].push_back(j);
            }
        }
    }
    dfs(0);
    memset(visited,0,N);
    for (int i=0; i<N; i++) {
        int temp = adj[i].size();
        for (int j=0; j<temp; j++) {
            adj[i].erase(adj[i].begin());
        }
    }
    if (counter == N) {
        return true;
    }
    else return false;
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("moocast");
    cin >> N;
    int left = 0, right = 1e10, middle;
    for (int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
    }
    while (left < right) {
        middle = (left + right)/2;
        if (!isConnected(middle)) {
            left = middle+1;
        }
        else {
            right = middle;
        }
    }
    cout << left;
}
