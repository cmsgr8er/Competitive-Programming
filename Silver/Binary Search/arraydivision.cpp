#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int n,k;
bool ok(vl a, ll sub) {
	ll sum = 0, divs = 1;
	for (int i=0; i<a.size(); i++) {
		if (sum + a[i] <= sub) sum += a[i];
		else {
			sum = a[i]; divs++;
		}
	}
	if (divs <= k) return true;
	else return false;
}
int main() {
	cin >> n >> k;
	vl x(n);
	ll m = 0;
	for (int i=0; i<n; i++) {
		cin >> x[i];
		m = max(m, x[i]);
	}
	ll left = m, right = n * 1e9;
	while (left < right) {
		ll middle = (left + right)/2;
		if (ok(x, middle)) right = middle;
		else left = middle+1;
	}
	cout << left;
}
