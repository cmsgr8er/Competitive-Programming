#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
ll sz, ups = 0, downs = 0, lefts = 0, rights = 0;
bool ok(ll moves, ll x, ll y, ll a, ll b) {
	x += rights * (moves / sz) - lefts* (moves/sz);
	y += ups * (moves/sz) - downs*(moves/sz);
	ll residue = moves%sz;
	for (int i=0; i<residue; i++) {
		char c = s[i];
		if (c == 'U') y++;
		else if (c=='D') y--;
		else if (c=='L') x--;
		else x++;
	}
	return moves >= abs(b-y) + abs(a-x);
}

int main() {
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2 >> sz >> s;
	for (int i=0; i<sz; i++) {
		if (s[i] == 'U') ups++;
		else if (s[i]=='D') downs++;
		else if (s[i]=='L') lefts++;
		else rights++;
	}
	ll left = 1, right = 9e18;
	while (left < right) {
		ll middle = left + (right-left)/2;
		if (ok(middle, x1, y1, x2, y2)) right = middle;
		else left = middle+1;
//		cout << left << " " << right << endl;
	}
	if (left >= 9e18) cout << -1;
	else cout << left;
}
