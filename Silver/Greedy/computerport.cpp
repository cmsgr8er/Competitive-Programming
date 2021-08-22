#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll u, p, b, m; cin >> u >> p >> b >> m;
	vector<pair<ll, string>> ports(m);
	for (int i=0; i<m; i++) {
		ll x; string s; cin >> x >> s;
		ports[i] = {x,s};
	}
	sort(ports.begin(), ports.end());
	ll num = 0, cost = 0;
	for (int i=0; i<m; i++) {
		if (ports[i].second == "USB") {
			if (u>0) {
				u--; num++; cost += ports[i].first;
			}
			else if (b>0) {
				b--; num++; cost += ports[i].first;
			}
		}
		if (ports[i].second == "PS/2") {
			if (p>0) {
				p--; num++; cost += ports[i].first;
			}
			else if (b>0) {
				b--; num++; cost += ports[i].first;
			}
		}
	}
	cout << num << " " << cost;
}
