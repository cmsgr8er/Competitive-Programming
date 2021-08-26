#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	int n,q; cin >> n >> q;
	vector<int> bales(n);
	for (int i=0; i<n; i++) cin >> bales[i];
	sort(bales.begin(), bales.end());
	for (int i=0; i<q; i++) {
		int a,b; cin >> a >> b;
		int lo = lower_bound(bales.begin(), bales.end(), a) - bales.begin();
		int hi = upper_bound(bales.begin(), bales.end(), b) - bales.begin();
		cout << hi - lo << endl;
	}
}
