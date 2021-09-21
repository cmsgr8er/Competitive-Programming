#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	int n, b; cin >> n >> b;
	vector<pair<int, int>> tiles(n), sortedtiles;
	vector<int> values(n);
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		tiles[i] = {x, i}; values[i] = x;
	}
	sortedtiles.push_back(tiles[0]);
	sortedtiles.push_back(tiles[n-1]);
	tiles.erase(tiles.begin());
	tiles.erase(prev(tiles.end()));
	sort(tiles.begin(), tiles.end()); sort(values.begin(), values.end());
	for (int i=0; i<tiles.size(); i++) sortedtiles.push_back(tiles[i]);
	multiset<int> index, diff; vector<int> lo(n-1);
	index.insert(n-1); index.insert(0); diff.insert(n-1); lo[0] = n-1;
	for (int i=1; i<n-1; i++) {
		index.insert(sortedtiles[i+1].second);
		auto it = index.lower_bound(sortedtiles[i+1].second);
		diff.erase(diff.lower_bound(*next(it) - *prev(it)));
		diff.insert(*it - *prev(it)); diff.insert(*next(it) - *it);
		lo[i] = *diff.rbegin();
	}
	for (int i=0; i<b; i++) {
		int a,b; cin >> a >> b;
		int fewer = upper_bound(values.begin(), values.end(), a) - values.begin();
		if (lo[fewer-2] <= b) cout << 1;
		else cout << 0;
		cout << endl;
	}
}
