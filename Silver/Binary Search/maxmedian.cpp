#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
ll n, k;
bool ok(vl a, ll s) {
	ll ops = 0;
	for (int i=0; i<a.size(); i++) {
		if (s-a[i] > 0) ops += s-a[i];
	}
	if (ops <= k) return true;
	else return false;
}

int main() {
	cin >> n >> k;
	vl x(n), y;
	for (int i=0; i<n; i++) cin >> x[i];
	sort(x.begin(), x.end());
	for (int i=n/2; i<n; i++) y.push_back(x[i]);
	ll left = 1, right = 2e9;
	while (left < right) {
		ll middle = left + (right - left + 1)/2;
		if (ok(y, middle)) left = middle;
		else right = middle-1;
	}
	cout << left;

}
