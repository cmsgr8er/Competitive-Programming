// This is a stupid problem.

#include <bits/stdc++.h>
using namespace std;
vector<int> parity[2], adj[2510];
void dfs(int node, int prev, int type) {
	parity[type].push_back(node);
	for (auto u: adj[node]) {
		if (u != prev) dfs(u, node, 1-type);
	}
}
int main() {
	freopen("clocktree.in", "r", stdin);
	freopen("clocktree.out", "w", stdout);
	int n, c1=0, c2=0; cin >> n;
	vector<int> value(2510);
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		value[i+1] = 12-x;
	}
	for (int i=0; i<n-1; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1,0,0);
	for (int i=0; i<parity[0].size(); i++) {
		c1 = (c1 + value[parity[0][i]])%(12);
	}
	for (int i=0; i<parity[1].size(); i++) {
		c2 = (c2 + value[parity[1][i]])%(12);
	}
	if ((c1+1)%12 == c2%12) cout << parity[0].size();
	else if ((c2+1)%12 == c1%12) cout << parity[1].size();
	else if (c1 == c2) cout << n;
	else cout << 0;
}
