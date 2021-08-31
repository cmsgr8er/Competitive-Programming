#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int> a, int k, int r) {
	int counter = 0, num = 0;
	while (counter < a.size()) {
		num++;
		counter = upper_bound(a.begin(), a.end(), a[counter] + 2*r) - a.begin();
	}
	return num <= k;
}

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	int n,K; cin >> n >> K;
	vector<int> x(n);
	for (int i=0; i<n; i++) cin >> x[i];
	sort(x.begin(), x.end());
	int left = 0, right = 1e9;
	while (left < right) {
		int middle = (left + right)/2;
		if (ok(x,K, middle)) right = middle;
		else left = middle+1;
	}
	cout << left;
}
