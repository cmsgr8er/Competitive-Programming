#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+10;
vector<int> adj[MN];
double ev[MN];

void dfs(int node, int prev) {
	for (auto u: adj[node]) {
		if (u != prev) {
			dfs(u, node);
			if (node != 1) ev[node] += ev[u]/ (adj[node].size()-1);
			else ev[node] += ev[u]/ adj[node].size();
		}
	}
}

int main() {
	int n; cin >> n;
	if (n != 1) {
		for (int i=0; i<n-1; i++) {
			int a,b; cin >> a >> b;
			adj[a].push_back(b); adj[b].push_back(a);
		}
		for (int i=1; i<=n; i++) {
			if (adj[i].size()==1 && i!= 1) ev[i] = 0;
			else ev[i] = 1;
		}
		dfs(1,0);
		cout.precision(7); cout << ev[1];
	}
	else cout << 0;
}
