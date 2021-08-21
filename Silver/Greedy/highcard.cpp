#include <bits/stdc++.h>
using namespace std;
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("highcard");
	int n, answer=0; cin >> n;
	vector<int> list(2*n), bessie, elsa;
	vector<bool> bad(2*n);
	for (int i=0; i<2*n; i++) list[i] = i+1;
	for (int i=1; i<=n; i++) {
		int x; cin >> x; x--;
		elsa.push_back(x+1);
		bad[x] = true;
	}
	for (int i=0; i<2*n; i++) {
		if (!bad[i]) bessie.push_back(i+1);
	}
	sort(bessie.begin(), bessie.end());
	for (int i=0; i<n; i++) {
		auto it = lower_bound(bessie.begin(), bessie.end(), elsa[i]);
		if (it != bessie.end()) {
			answer++;
			bessie.erase(it);
		}
		else {
			bessie.erase(bessie.begin());
		}
	}
	cout << answer;
}
