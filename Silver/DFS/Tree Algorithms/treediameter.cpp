#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+10;
bool visited[MN];
vector<int> adj[MN];
int dist[MN], largest = 0;

void dfs(int node, int d) {
	visited[node] = true;
	dist[node] = d; largest = max(largest, d);
	for (auto u: adj[node]) {
		if (!visited[u]) {
			dfs(u, d+1);
		}
	}
}

int main() {
	int n, a; cin >> n;
	for (int i=0; i<n-1; i++) {
		int x,y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1; i<=n; i++) {
		if (dist[i] == largest) a = i;
		dist[i] = 0; visited[i] = 0;
	}
	largest = 0;
	dfs(a,0);
	cout << largest;

}
