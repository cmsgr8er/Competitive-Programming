#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	int n; cin >> n;
	int answer = n;
	vector<int> w(n);
	for (int i=0; i<n; i++) cin >> w[i];
	sort(w.rbegin(), w.rend());
	for (int i=0; i<n; i++) {
		if (w[i] < i) {
			answer = i; break;
		}
	}
	cout << answer;
}
