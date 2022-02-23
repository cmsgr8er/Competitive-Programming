#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

int main() {
	ll n, answer = 0; cin >> n;
	vl h(n), index(n+1); for (int i=0; i<n; i++) cin >> h[i];
	index[0] = 0;
	for (int i=0; i<n; i++) index[h[i]] = i;
	set<ll> s;
	s.insert(index[n]);
	for (int i=n-1; i>0; i--) {
		auto it = s.lower_bound(index[i]);
		if (it == s.begin()) answer += *it - index[i]+1;
		else if (it == s.end()) answer += index[i] - *prev(it)+1;
		else answer += *it - *prev(it)+2;
		s.insert(index[i]);
	}
	cout << answer;
}