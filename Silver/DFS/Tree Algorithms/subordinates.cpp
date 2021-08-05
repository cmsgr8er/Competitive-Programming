#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200010];
int subordinates[200010];

void count(int node) {
	if (adj[node].size() == 0) subordinates[node] = 0;
	else {
		for (auto u: adj[node]) {
			count(u);
			subordinates[node] += subordinates[u] + 1;
		}
	}
}

int main() {
	int n, x;
    cin >> n;
	for (int i=2; i<=n; i++) {
		cin >> x;
		adj[x].push_back(i);
	}
	count(1);
	for (int i=1; i<=n; i++) {
		cout << subordinates[i] << " ";
	}
}
