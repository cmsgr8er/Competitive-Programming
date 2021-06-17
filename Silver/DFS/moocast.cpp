// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 10;
int N;
bool visited[MN];
vector<int> adj[MN];

void dfs(int s) {
    visited[s] = true;
    for (auto u: adj[s]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int getMax(int node) {
    int count =0;
    dfs(node);
    for (int i=0; i<N; i++) {
        if (visited[i]) count++;
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
    setIO("moocast");
    cin >> N;
    int x[N], y[N], p[N], xdiff, ydiff, answer = 0;
    for (int i=0; i<N; i++) {
        cin >> x[i] >> y[i] >> p[i];
    }
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            xdiff = abs(x[i] - x[j]);
            ydiff = abs(y[i]-y[j]);
            if (p[i]*p[i] >= xdiff*xdiff + ydiff*ydiff) {
                adj[i].push_back(j);
            }
            if (p[j]*p[j] >= xdiff*xdiff + ydiff*ydiff) {
                adj[j].push_back(i);
            } 
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            visited[j] = false;
        }
        answer = max(answer, getMax(i));
    }
    cout << answer;
}
