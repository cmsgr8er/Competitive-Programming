#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	int n, answer = 0; cin >> n;
	vector<int> elsa(n), bessie, smaller(n/2), bigger(n/2);
	vector<bool> bad(2*n+1);
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		bad[x] = true;
		elsa[i] = x;
	}
	for (int i=1; i<=2*n; i++) {
		if (!bad[i]) bessie.push_back(i);
	}
	for (int i=0; i<n/2; i++) smaller[i] = bessie[i];
	for (int i=n/2; i<n; i++) bigger[i-n/2] = bessie[i];
	for (int i=0; i<n/2; i++) {
		auto it = lower_bound(bigger.begin(), bigger.end(), elsa[i]);
		if (it != bigger.end()) {
			bigger.erase(it);
			answer++;
		}
		else bigger.erase(bigger.begin());
	}
	for (int i=n/2; i<n; i++) {
		auto it = lower_bound(smaller.begin(), smaller.end(), elsa[i]);
		if (it != smaller.begin()) {
			smaller.erase(prev(it));
			answer++;
		}
		else smaller.erase(prev(smaller.end()));
	}
	cout << answer;
}
