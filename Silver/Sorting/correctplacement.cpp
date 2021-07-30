#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for (int p=0; p<t; p++) {
		int n; cin >> n;
		map<pair<int, int>, int> order;
		set<int> endpoints;
		vector<int> h(n), w(n), x(n), y(n), a(n), b(n), coordinates;
		for (int i=0; i<n; i++) {
			cin >> h[i] >> w[i];
			endpoints.insert(h[i]); endpoints.insert(w[i]);
		}
		coordinates = vector<int>(endpoints.begin(), endpoints.end());
		vector<pair<int, int>> index(n), psum(n);
		for (int i=0; i<n; i++) {
			index[i].first = lower_bound(coordinates.begin(), coordinates.end(), h[i]) - coordinates.begin();
			index[i].second = lower_bound(coordinates.begin(), coordinates.end(), w[i]) - coordinates.begin();
			if (index[i].first > index[i].second) index[i] = {index[i].second, index[i].first};
			x[i] = index[i].first; y[i] = index[i].second;
			order[index[i]] = i;
		}
		sort(index.begin(), index.end());
		for (int i=0; i<n; i++) {
			a[i] = index[i].first;
			b[i] = index[i].second;
		}
		psum[0] = {b[0], 0};
		for (int i=1; i<n; i++) {
			psum[i].first = min(psum[i-1].first, b[i]);
			if (b[i] < psum[i-1].first) {
				psum[i].second = i;
			}
			else psum[i].second = psum[i-1].second;
		}
		for (int i=0; i<n; i++) {
			int subscript = lower_bound(a.begin(), a.end(), x[i]) - a.begin();
			if (subscript == 0) {
				cout << -1 << " ";
			}
			else if (psum[subscript-1].first < y[i]) {
				cout << order[index[psum[subscript-1].second]] + 1 << " ";
			}
			else cout << -1 << " ";
		}
		psum.clear(), index.clear(), coordinates.clear(),
		x.clear(), y.clear(), a.clear(), b.clear(), h.clear(), w.clear();
		cout << endl;
	}
}
