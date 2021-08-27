#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	vector<pair<int, int>> jiro(n);
	vector<int> ciel(m);
	for (int i=0; i<n; i++) {
		string s; cin >> s;
		int p; cin >> p;
		if (s == "DEF") jiro[i] = {1,p};
		else jiro[i] = {0,p};
	}
	sort(jiro.begin(), jiro.end());
	for (int i=0; i<m; i++) cin >> ciel[i];
	sort(ciel.rbegin(), ciel.rend());
	if (m<=n) {
		int t=0, answer = 0;
		while (t < m && jiro[t].first == 0) {
			if (ciel[t] >= jiro[t].second) {
				answer += ciel[t] - jiro[t].second;
				t++;
			}
			else break;
		}
		cout << answer;
	}
	else {
		int t=0, ans1 = 0;
		while (t < m && jiro[t].first == 0) {
			if (ciel[t] >= jiro[t].second) {
				ans1 += ciel[t] - jiro[t].second;
				t++;
			}
			else break;
		}
		sort(ciel.begin(), ciel.end());
		bool valid = true;
		int ok=0, tot =0, ans2 = 0;
		for (int i=0; i<n; i++) {
			if (jiro[i].first == 1) {
				tot++;
				auto it = upper_bound(ciel.begin(), ciel.end(), jiro[i].second);
				if (it != ciel.end()) {
					ciel.erase(it);
					ok++;
				}
				else break;
			}
		}
		if (ok==tot) {
			int counter = 0, sum=0, j = 0;
			for (int i=0; i<ciel.size(); i++) sum += ciel[i];
			for (int i=0; i<n; i++) {
				if (jiro[i].first == 0) {
					j += jiro[i].second;
					auto it = lower_bound(ciel.begin(), ciel.end(), jiro[i].second);
					if (it != ciel.end()) ciel.erase(it);
					else {
						valid = false;
						break;
					}
				}
			}
			if (valid) {
				ans2 = sum - j;
			}
		}
		cout << max(ans1, ans2);
	}
}
