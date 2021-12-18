#include <bits/stdc++.h>
using namespace std;
int cows[100010], adj[100010];
bool visited[100010];
vector<int> comps[100010];
int c=1;

void dfs(int node) {
	visited[node] = true;
	comps[c].push_back(node);
	if (!visited[adj[node]]) dfs(adj[node]);
}

int main() {
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	int n, m, k; cin >> n >> m >> k;
	for (int i=1; i<=n; i++) cows[i] = i;
	for (int i=0; i<m; i++) {
		int x,y; cin >> x >> y;
		for (int j=x; j<=(x+y)/2; j++) {
			swap(cows[j], cows[y+x-j]);
		}
	}
	for (int i=1; i<=n; i++) {
		visited[i] = false;
		adj[cows[i]] = i;
	}
	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			dfs(i);
			c++;
		}
	}
	int answer[n+1];
	for (int i=1; i<=c-1; i++) {
		int sz = comps[i].size();
		int r = k%sz;
		for (int j=0; j<sz; j++) {
			answer[comps[i][(j+r)%sz]] = comps[i][j];
		}
	}
	for (int i=1; i<=n; i++) cout << answer[i] << endl;
} 