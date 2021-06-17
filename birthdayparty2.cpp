// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 10;
int p, q;
bool visited[MN];
vector<int> adj[MN];

void dfs(int node) {
    visited[node] = true;
    for (auto u: adj[node]) {
        if (!visited[u]) dfs(u);
    }
}

bool canInvite(int a, int b) {
    bool status = true;;
    for (int i=0; i< adj[a].size(); i++) {
        if (adj[a][i] == b) adj[a].erase(adj[a].begin() + i);
    }
    for (int i=0; i< adj[b].size(); i++) {
        if (adj[b][i] == a) adj[b].erase(adj[b].begin() + i);
    }
    dfs(0);
    adj[a].push_back(b);
    adj[b].push_back(a);
    for (int i=0; i<p; i++) {
        if (!visited[i]) status = false;
    }
    for (int i=0; i<p; i++) {
        visited[i] = false;
    }
    return status;
}

int main() {
    int dummy;
    cin >> p >> q;
    while (p != 0 && q!=0) {
        bool answer = false;
        int one[q], two[q];
        for (int i=0; i<q; i++) {
            cin >> one[i] >> two[i];
            adj[one[i]].push_back(two[i]);
            adj[two[i]].push_back(one[i]);
        }
        for (int i=0;i <p; i++) {
            visited[i] = false;
        }
        for (int i=0; i<q; i++) {
            if (!canInvite(one[i], two[i])) {
                answer = true;
            }
        }
        if (answer) cout << "Yes" << endl;
        if (!answer) cout << "No" << endl;
        
        for (int i=0; i<p; i++) {
            dummy = adj[i].size();
            for (int j=0; j<dummy; j++) {
                adj[i].erase(adj[i].begin());
            }
        }
        cin >> p >> q;
    }
}
