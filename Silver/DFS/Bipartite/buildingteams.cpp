// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 10;
int n, m;
bool visited[MN], impossible = false;
vector<int> adj[MN];
int team[MN];

void dfs(int node) {
	visited[node] = true;
	for (auto u:adj[node]) {
		if (visited[u] && team[u] != 2/team[node]) impossible = true;
		else if (!visited[u]){
			team[u] = 2/team[node];
			dfs(u);
		}
	}
}

int main() {
	cin >> n >> m;
	int a,b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=1; i<n+1; i++) {
		if (!visited[i]) {
			team[i] = 1;
			dfs(i);
		}
	}
	if (impossible) cout << "IMPOSSIBLE";
	else {
		for (int i=1; i<=n; i++) {
			cout << team[i] << " ";
		}
	}
}
