#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> end(n), a(n);
	vector<vector<int>> sub;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) {
		int lo=0, hi=sub.size(), index;
		while (lo < hi) {
			index = (lo + hi)/2;
			if (end[index] <= a[i]) hi = index;
			else lo = index+1;
		}
		if (lo != sub.size() && sub.size() != 0) {
			end[lo] = a[i];
			sub[lo].push_back(a[i]);
		}
		else {
			vector<int> v; v.push_back(a[i]);
			sub.push_back(v);
			end[sub.size()-1] = a[i];
			v.clear();
		}
	}
	for (int i=0; i<sub.size(); i++) {
		for (int j=0; j< sub[i].size(); j++) {
			cout << sub[i][j] << " ";
		}
		cout << endl;
	}
}
