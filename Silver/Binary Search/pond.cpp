#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin >> n >> k;
	int a[n][n], num[n][n], psum[n+1][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
	int lo=0, hi=1e9, median;
	while (lo < hi) {
		median = (lo+hi)/2;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++){ 
				num[i][j] = (a[i][j] > median);
			}
		}
		for (int j=0; j<n; j++) psum[0][j] = 0;
		for (int i=1; i<=n; i++) {
			for (int j=0; j<n; j++) {
				psum[i][j] = psum[i-1][j] + num[i-1][j];
			}
		}
		bool ok = false;
		for (int i=1; i<=n-k+1; i++) {
			for (int j=0; j<=n-k; j++) {
				int sum=0;
				for (int h=j; h<j+k; h++) {
					sum += psum[i+k-1][h] - psum[i-1][h];
				}
				ok = ok || (sum < (k*k)/2+1);
			}
		}
		if (ok) hi = median;
		else lo = median+1;
	}
	cout << lo;
} 