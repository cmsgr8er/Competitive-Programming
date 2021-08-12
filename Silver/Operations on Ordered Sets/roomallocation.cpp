#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	priority_queue<int> available;
	for (int i=1; i<=n; i++) {
		available.push(n-i);
	}
	map<int, set<int>> arrive, leave;
	vector<int> num(n);
	set<int> endpoints;
	for (int i=0; i<n; i++) {
		int x,y; cin >> x >> y;
		arrive[x].insert(i); leave[y].insert(i);
		endpoints.insert(x); endpoints.insert(y);
	}
	for (auto it = endpoints.begin(); it != endpoints.end(); it++) {
		for (auto s: arrive[*it]) {
			num[s] = n - available.top();
			available.pop();
		}
		for (auto s: leave[*it]) {
			available.push(n-num[s]);
		}
	}
	int largest = 0;
	for (int i=0; i<n; i++) {
		largest = max(largest, num[i]);
	}
	cout << largest << endl;
	for (int i=0; i<n; i++) {
		cout << num[i] << " ";
	}
}
