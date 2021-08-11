#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[5001];
bool visited[5001];
vector<int> relevance(5001);

void dfs(int node, int start) {
	visited[node] = true;
	for (auto u: adj[node]) {
        if (!visited[u.first]) {
            if (node == start) relevance[u.first] = u.second;
            else relevance[u.first] = min(relevance[node],u.second);
            dfs(u.first, start);
        }
	}
}

int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	int N,Q; cin >> N >> Q;
	for (int i=1; i<N; i++) {
		int p,q,r; cin >> p >> q >> r;
		adj[p].push_back({q,r});
		adj[q].push_back({p,r});
	}
	for (int i=0; i<Q; i++) {
		for (int j=1; j<=N; j++) relevance[j] = 1e9;
		int k, v, answer = 0; cin >> k >> v;
		dfs(v,v);
		for (int j=1; j<=N; j++) {
			if (relevance[j]>= k) answer++;
		}
		cout << answer-1 << endl;
		memset(visited, 0, N+1);
	}
}
