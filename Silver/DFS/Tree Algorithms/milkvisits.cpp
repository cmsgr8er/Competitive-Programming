#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+10;
int components[MN], comp = 1;
vector<int> adj[MN];
bool visited[MN];
char milk[MN];

void dfs(int node, char c) {
	visited[node] = true;
	components[node] = comp;
	for (auto u: adj[node]) {
		if (!visited[u] && milk[u] == c) dfs(u, c);
	}
}

int main() {
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> milk[i];
	for (int i=0; i<n-1; i++) {
		int x,y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			dfs(i, milk[i]);
			comp++;
		}
	}
	for (int i=0; i<m; i++) {
		char k; int a,b;
		cin >> a >> b >> k;
		if (components[a] != components[b]) cout << 1;
		else if (milk[a] == k) cout << 1;
		else cout << 0;
	}
}
