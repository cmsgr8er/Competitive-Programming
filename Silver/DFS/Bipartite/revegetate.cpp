#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 10;
bool visited[MN], impossible = false;
vector<pair<char, int>> adj[MN];
int N, M, type[MN];
void dfs(int node) {
	int variety;
	visited[node] = true;
	for (auto u:adj[node]) {
		if (get<0>(u) == 'S') variety = type[node];
		else variety = 2/type[node];
		if (visited[get<1>(u)] && type[get<1>(u)] != variety) {
			impossible = true;
		}
		else if (!visited[get<1>(u)]) {
			type[get<1>(u)] = variety;
			dfs(get<1>(u));
		}
	}
}
int components() {
	int parts = 0;
	for (int i=1; i<=N; i++) {
		if (!visited[i]) {
			type[i] = 1;
			dfs(i);
			parts++;
		}
	}
	return parts;
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("revegetate");
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		int a,b;
		char style;
		cin >> style >> a >> b;
		adj[a].push_back({style, b});
		adj[b].push_back({style, a});
	}
	int parts = components();
	if (impossible) {
		cout << 0;
	}
	else {
		cout << 1;
		for (int i=0; i<parts; i++) {
			cout << 0;
		}
	}


}


