#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, answer=0; cin >> n;
	vector<int> adj[n+1];
	for (int i=0; i<n-1; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i=2; i<=n; i++) {
		if (adj[i].size() > 1) {
			answer += (int)(log2 ((double) (adj[i].size()-1))) + 1;
		}
	}
	answer += n-1;
	answer += (int) (log2 ((double) adj[1].size()))+1;
	cout << answer;
}
