#include <bits/stdc++.h>
using namespace std;

const int MN = 4e5 + 10;
bool visited[MN] = {false};
vector<int> adj[MN], one, two;
int team[MN] = {0};

void dfs(int node) {
	visited[node] = true;
	for (auto u: adj[node]) {
		if (!visited[u]) {
			team[u] = 3-team[node];
			if (team[u] == 1) one.push_back(u);
			else if (team[u] == 2) two.push_back(u);
			dfs(u);
		}
	}
}

int main() {
	int t, n, m, a, b, tracker = 0;
	cin >> t;
	for (int i=0; i<t; i++) {
		one.push_back(tracker + 1);
		cin >> n >> m;
		for (int j=0; j<m; j++) {
			cin >> a >> b;
			adj[tracker + a].push_back(tracker + b);
			adj[tracker + b].push_back(tracker + a);
		}
		team[tracker + 1] = 1;
		dfs(tracker + 1);
		if (one.size() <= two.size()) {
			cout << one.size() << endl;
			for (int k=0; k <one.size(); k++) {
				cout << one[k] - tracker << " ";
			}
		}
		else {
			cout << two.size() << endl;
			for (int k=0; k<two.size(); k++) {
				cout << two[k] - tracker << " ";
			}
		}
		cout << endl;
		one.clear();
		two.clear();
		tracker += n;
	}

}
