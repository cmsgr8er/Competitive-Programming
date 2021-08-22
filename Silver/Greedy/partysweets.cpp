#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main() {
	ll n, m, answer=0; cin >> n >> m;
	vl b(n), g(m), bdeg(n), gdeg(m);
	for (int i=0; i<n; i++) {
		ll x; cin >> x;
		b[i] = x;
	}
	for (int i=0; i<m; i++) {
		int x; cin >> x; answer += x;
		g[i] = x;
	}
	sort(b.rbegin(), b.rend()); sort(g.rbegin(), g.rend());
	if (b[0] > g[m-1]) answer = -1;
	else {
		if (b[0] == g[m-1]) {
			for (int i=1; i<n; i++) answer += m*b[i];
		}
		else {
			answer += b[0] + (m-1)*b[1];
			for (int i=2; i<n; i++) answer += m*b[i];
		}
	}
	cout << answer;
}
