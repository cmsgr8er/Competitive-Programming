#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> k;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		auto it = upper_bound(k.begin(), k.end(), x);
		if (it == k.end()) k.push_back(x);
		else k[it-k.begin()] = x;
	}
	cout << k.size();
}
