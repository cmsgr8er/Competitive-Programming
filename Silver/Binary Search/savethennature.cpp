#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x,y,a,b, k;
bool ok(vector<ll> p, ll sz) {
	ll c2=0, c1=0, both=0, profit=0;
	sort(p.rbegin(), p.rend());
	for (int i=1; i<=sz; i++) {
		if (i%a == 0 && i%b == 0) both++;
		else if (i%a == 0) c1++;
		else if (i%b == 0) c2++;
	}
	for (int i=0; i<both; i++) profit += (x + y) * p[i];
	if (x > y) {
		for (int i=both; i < both + c1; i++) profit += x * p[i];
		for (int i=both+c1; i< both+c1+c2; i++) profit += y * p[i];
	}
	else {
		for (int i=both; i < both + c2; i++) profit += y * p[i];
		for (int i=both+c2; i< both+c1+c2; i++) profit += x * p[i];
	}
	return profit >= k;
}

int main() {
	int q; cin >> q;
	for (int tc =0; tc < q; tc++) {
		ll n; cin >> n;
		vector<ll> prices(n);
		for (int i=0; i<n; i++) {
			ll c; cin >> c;
			prices[i] = c/100;
		}
		cin >> x >> a >> y >> b >> k;
		ll lo=1, hi=n+1, tickets;
		while (lo < hi) {
			tickets = (lo + hi)/2;
			if (ok(prices, tickets)) hi = tickets;
			else lo = tickets + 1;
		}
		if (lo == n+1) cout << -1 << endl;
		else cout << lo << endl;
		prices.clear();
	}
}
