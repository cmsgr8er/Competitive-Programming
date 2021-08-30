#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}
int main() {
	int n; cin >> n;
	vector<pair<int, int>> orig(n), grid(n);
	map<int, int> ccx, ccy;
	vector<int> x(n), y(n);
	int dp[n+1][n+1], points[n+1][n+1];
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			dp[i][j] = 0; points[i][j] = 0;
		}
	}
	// Coordinate Compression:
	for (int i=0; i<n; i++) {
		int a,b; cin >> a >> b;
		orig[i] = {a,b};
		x[i] = a; y[i] = b;
	}
	sort(x.begin(), x.end()); sort(y.begin(), y.end());
	for (int i=0; i<n; i++) {
		ccx[x[i]] = i; ccy[y[i]] = i;
	}
	for (int i=0; i<n; i++) {
		grid[i] = {ccx[orig[i].first]+1, ccy[orig[i].second]+1};
		points[grid[i].first][grid[i].second]++;
	}
	sort(grid.begin(), grid.end(), cmp);
	// dp finds how many cows are left and lower than given cow:
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + points[i][j];
		}
	}
	long long answer = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<i; j++) {
			int left = min(grid[i].first, grid[j].first), right = max(grid[i].first, grid[j].first), l;
			if (left == grid[j].first) l = dp[left][grid[i].second]-dp[left][grid[j].second]+1;
			else l = dp[left][grid[i].second]-dp[left][grid[j].second];
			answer += l * (1+dp[n][grid[i].second]-dp[right][grid[i].second]-dp[n][grid[j].second] + dp[right][grid[j].second]);
		}
	}
	cout << answer + n+1;


}
