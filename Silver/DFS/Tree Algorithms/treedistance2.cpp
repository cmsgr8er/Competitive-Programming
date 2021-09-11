#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+10;
using ll = long long;
int child[MN], n;
ll answer[MN];
vector<int> adj[MN], components[MN];
int dist[MN], id[MN], num = 0;
void dfs(int node, int prev, int d) {
	dist[node] = d;
	for (auto u: adj[node]) {
		if (u != prev) {
			dfs(u, node, d+1);
		}
	}
}
void subtree(int node, int prev) {
	child[node] = 1;
	for (auto u: adj[node]) {
		if (u != prev) {
			subtree(u, node);
			child[node] += child[u];
		}
	}
}
void solve(int node, int prev) {
	for (auto u: adj[node]) {
		if (u != prev) {
			answer[u] = answer[node] + n - 2*child[u];
			solve(u, node);
		}
	}
}
int main() {
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1, 0, 0);
	subtree(1,0);
	for (int i=2; i<=n; i++) answer[1] += dist[i];
	solve(1,0);
	for (int i=1; i<=n; i++) cout << answer[i] << " ";


}
