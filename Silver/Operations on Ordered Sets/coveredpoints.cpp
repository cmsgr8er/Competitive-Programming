#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n; cin >> n;
	set<ll> endpoints;
	map<ll, ll> left, right, k;
	for (int i=0; i<n; i++) {
		ll a,b; cin >> a >> b;
		endpoints.insert(a); endpoints.insert(b+1);
		left[a]++; right[b+1]++;
	}
	int value = 0;
	for (auto i=endpoints.begin(); i != prev(endpoints.end()); i++) {
		value += left[*i] - right[*i];
		k[value] += *next(i) - *i;
	}
	for (int i=1; i<=n; i++) {
		cout << k[i] << " ";
	}
}
