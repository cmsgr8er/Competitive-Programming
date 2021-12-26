#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int a[n], b[n]; for (int i=0; i<n; i++) cin >> a[i] >> b[i];
	long long afreq[m+1], bfreq[m+1];
	for (int i=0; i<=m; i++) {
		afreq[i] = 0; bfreq[i] = 0;
	}
	for (int i=0; i<n; i++) {
		afreq[a[i]]++; bfreq[b[i]]++;
	}
	long long apart[2*m+1], bpart[2*m+1];
	for (int i=0; i<=2*m; i++) {
		apart[i]=0; bpart[i] = 0;
		for (int j=max(i-m, 0); j<=min(i,m); j++) {
			apart[i] += afreq[j]*afreq[i-j];
			bpart[i] += bfreq[j]*bfreq[i-j];
		}
	}
	long long dp[2*m+1];
	for (int i=0; i<=2*m; i++) dp[i] = 0;
	dp[0] = apart[0];
	for (int i=1; i<=2*m; i++) {
		dp[i] = dp[i-1] - bpart[i-1] + apart[i];
	}
	for (int i=0; i<=2*m; i++) {
		cout << dp[i] << endl;
	}
} 