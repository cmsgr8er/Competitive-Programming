#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for (int tc=0; tc < t; tc++) {
		int n,m,a,b, answer=0; cin >> n >> m >> a >> b;
		if (a > b) {
			a = n+1-a;
			b = n+1-b;
		}
		vector<int> s(m); for (int i=0; i<m; i++) cin >> s[i];
		sort(s.begin(), s.end());
		for (int pos=b; pos>a+1; pos--) {
			auto it = upper_bound(s.begin(), s.end(), pos-2);
			if (it != s.begin()) {
				answer++;
				s.erase(prev(it));
			}
			else break;
		}
		cout << answer << endl;
		s.clear();
	}
}