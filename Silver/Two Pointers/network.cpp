#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> cities(n), towers(m);
	for (int i=0; i<n; i++) {
		cin >> cities[i];
	}
	for (int i=0; i<m; i++) {
		cin >> towers[i];
	}
	int city = 0, r = 0, tower = 0;
	for (city = 0; city < n; city++) {
		if (tower < m-1) {
			while (cities[city] >= towers[tower+1] && tower < m-1) tower++;
			r = max(r, min(abs(cities[city] - towers[tower]), abs(cities[city]-towers[tower+1])));
		}
		else {
			r = max(r, abs(cities[city] - towers[m-1]));
		}
	}
	cout << r;
}
