#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,d, K=1e9+9; cin >> n >> d;
	vector<long long> h(n); for (int i=0; i<n; i++) cin >> h[i];
	sort(h.begin(), h.end());
	vector<long long> dp(n); dp[0] = 1;
	for (int i=1; i<n; i++) {
		int lo = lower_bound(h.begin(), h.end(), h[i]-d)-h.begin();
		long long ok = i-lo;
		dp[i] = (dp[i-1]*(ok+1))%K;
	}
	cout << dp[n-1];
} 