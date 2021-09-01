#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool ok(ll median, ll n) {
	ll less = 0;
	for (ll i=1; i<= n; i++) {
		less += min(median/i, n);
	}
	return less >= (n*n+1)/2;
}

int main() {
	ll N;
	cin >> N;
	ll left = N, right = 1e12;
	while (left < right) {
		ll middle = (left + right)/2;
		if (ok(middle, N)) right = middle;
		else left = middle+1;
	}
	cout << left;
}
