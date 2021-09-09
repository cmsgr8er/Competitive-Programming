#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+10;
int dist = 0, far[MN], x[MN], y[MN], p, q;
vector<int> adj[MN];
void search(int node, int prev, int d) {
	dist = max(dist, d);
	far[node] = d;
	for (auto u: adj[node]) {
		if (u != prev) search(u, node, d+1);
	}
}
void vertex1(int node, int prev, int d) {
	x[node] = d;
	for (auto u: adj[node]) {
		if (u != prev) vertex1(u, node, d+1);
	}
}
void vertex2(int node, int prev, int d) {
	y[node] = d;
	for (auto u: adj[node]) {
		if (u != prev) vertex2(u, node, d+1);
	}
}
int main() {
	int n; cin >> n;
	for (int i=0; i<n-1; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	search(1, 0, 0);
	for (int i=1; i<=n; i++) {
		if (far[i] == dist) p = i;
		far[i] = 0;
	}
	dist = 0;
	search(p, 0, 0);
	for (int i=1; i<=n; i++) {
		if (far[i] == dist) q = i;
	}
	vertex1(p, 0, 0); vertex2(q,0,0);
	for (int i=1; i<=n; i++) cout << max(x[i], y[i]) << " ";
}
