#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
map<ll, ll> endpoint;

bool ok(vl x, ll n, ll radius) {
	ll counter = x[0], left = 0, tot = 0;
	while (counter <= endpoint[x[x.size()-1]]) {
		tot++;
		if (endpoint[x[left]] < counter) {
			left = upper_bound(x.begin(), x.end(), counter) - x.begin() - 1;
			if (endpoint[x[left]] < counter) left++;
			counter = max(counter, x[left]);
		}
		counter += radius;
	}
	return tot >= n;
}

int main() {
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	ll N, M; cin >> N >> M;
	vl leftpoints(M);
	for (int i=0; i<M; i++) {
		ll x,y; cin >> x >> y;
		leftpoints[i] = x; endpoint[x] = y;
	}
	sort(leftpoints.begin(), leftpoints.end());
	ll left = 0, right = 1e18;
	while (left < right) {
		ll middle = (left + right + 1)/2;
		if (ok(leftpoints, N, middle)) left = middle;
		else right = middle-1;
	}
	cout << left;
}
