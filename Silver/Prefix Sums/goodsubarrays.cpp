#include <bits/stdc++.h>
using namespace std;
int main() {
	const int MN = 1e5+10;
	int n, t, a[MN];
	char x;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		for (int k=0; k<n; k++) {
			cin >> x;
			a[k] = x-'1';
		}
		map<int, int> sums;
		sums[0] = 1;
		long long psum = 0, answer = 0;
		for (int j=0; j<n; j++) {
			psum+=a[j];
			answer += sums[psum];
			sums[psum]++;
		}
		cout << answer << endl;
		memset(a, 0, n+1), sums.clear();
	}
}
