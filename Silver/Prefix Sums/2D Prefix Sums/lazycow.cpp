#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
	int n,k, answer =0, total; cin >> n >> k;
	int grass[n+1][n+1], psum[n+1][n+1];
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> grass[i][j];
		}
	}
	for (int c=1; c<=n; c++) {
		for (int r=1; r<=n; r++) {
			psum[r][c] = psum[r-1][c] + grass[r][c];
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			total=0;
			for (int c = max(1,j-k); c <= min(j+k,n); c++) {
				int diff = k - abs(j-c);
				total += psum[min(n,i+diff)][c] - psum[max(1,i-diff)-1][c];
			}
			answer = max(answer, total);
		}
	}
	cout << answer;
}
