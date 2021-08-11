#include <bits/stdc++.h>
using namespace std;

int main() {
	multiset<int> prices;
	int n,m; cin >> n >> m;
	for (int i=0; i<n; i++) {
		int h; cin >> h;
		prices.insert(h);
	}
	for (int i=0; i<m; i++) {
		int t; cin >> t;
		auto it = prices.upper_bound(t);
		if (it != prices.begin()) {
            cout << *--it;
			prices.erase(it);
		}
		else cout << -1;
		cout << endl;
	}
}
