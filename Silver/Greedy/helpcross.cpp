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
	setIO("helpcross");
	int c,n, answer=0; cin >> c >> n;
	vector<int> chicken(c), start(n), end(n);
	for (int i=0; i<c; i++) cin >> chicken[i];
	sort(chicken.begin(), chicken.end());
	vector<pair<int, int>> cows(n);
	for (int i=0; i<n; i++) {
		cin >> cows[i].second >> cows[i].first;
	}
	sort(cows.begin(), cows.end());
	for (int i=0; i<n; i++) {
		auto it = lower_bound(chicken.begin(), chicken.end(), cows[i].second);
		if (it != chicken.end() && *it <= cows[i].first) {
			answer++;
			chicken.erase(it);
		}
	}
	cout << answer;

}
