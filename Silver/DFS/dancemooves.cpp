#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+10;
vector<int> adj[MN];
bool visited[MN];
vector<int> components(MN);
int comp = 1;

void dfs(int node) {
    visited[node] = true;
    components[node] = comp;
    for (auto u: adj[node]) {
        if (!visited[u]) dfs(u);
    }
}

int main() {
    int n,k; cin >> n >> k;
    int a[k], b[k];
    for (int i=0; i<k; i++) cin >> a[i] >> b[i];
    vector<int> id(n+1);
    for (int i=1; i<=n; i++) id[i] = i;
    for (int i=0; i<k; i++) swap(id[a[i]], id[b[i]]);
    for (int i=1; i<=n; i++) adj[id[i]].push_back(i);
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            dfs(i);
            comp++;
        }
    }
    set<int> answer[MN];
    for (int i=1; i<=n; i++) {
        answer[components[i]].insert(i);
    }
    for (int i=0; i<k; i++) {
        swap(components[a[i]], components[b[i]]);
        answer[components[a[i]]].insert(a[i]);
        answer[components[b[i]]].insert(b[i]);
    }
    for (int i=1; i<=n; i++) cout << answer[components[i]].size() << endl;
}
