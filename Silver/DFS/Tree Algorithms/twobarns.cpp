#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+10;
vector<int> adj[MN];
bool visited[MN];
int component[MN], comp;

void dfs(int node) {
	visited[node] = true;
	component[node] = comp;
	for (auto u: adj[node]) {
		if (!visited[u]) dfs(u);
	}
}

int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int n, m; cin >> n >> m;
		for (int i=0; i<m; i++) {
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		comp = 1;
		for (int i=1; i<=n; i++) {
			if (!visited[i]) {
				dfs(i);
				comp++;
			}
		}
		comp--;
		vector<int> indices[comp+1];
		vector<long long> dist(comp+1), ndist(comp+1);
		for (int i=1; i<=n; i++) {
			indices[component[i]].push_back(i);
		}
		for (int i=1; i<=comp; i++) {
			dist[i] = n, ndist[i] = n;
			for (int u: indices[i]) {
				auto it = lower_bound(indices[component[1]].begin(), indices[component[1]].end(), u);
				if (it != indices[component[1]].end()) dist[i] = min(dist[i], (long long) *it - u);
				if (it != indices[component[1]].begin()) dist[i] = min(dist[i], (long long)u-*prev(it));
			}
			for (int u: indices[i]) {
				auto it = lower_bound(indices[component[n]].begin(), indices[component[n]].end(), u);
				if (it != indices[component[n]].end()) ndist[i] = min(ndist[i], (long long)*it - u);
				if (it != indices[component[n]].begin()) ndist[i] = min(ndist[i],(long long) u-*prev(it));
			}
		}
		long long answer = (long long) n*n;
		for (int i=1; i<=comp; i++) answer = min(answer, dist[i]*dist[i] + ndist[i]*ndist[i]);
		cout << answer << endl;
		for (int i=1; i<=n; i++) {
			visited[i] = false;
			adj[i].clear();
			component[i] = 0;
		}
		for (int i=0; i<=comp; i++) indices[i].clear();
		dist.clear(), ndist.clear();
	}
} 