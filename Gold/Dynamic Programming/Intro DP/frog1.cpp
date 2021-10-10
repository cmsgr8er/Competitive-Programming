#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int h[n], cost[n];
	for (int i=0; i<n; i++) cin >> h[i];
	cost[n-1] = 0; cost[n-2] = abs(h[n-1]-h[n-2]);
	for (int i=3; i<=n; i++) {
		cost[n-i] = min(cost[n-i+2] + abs(h[n-i+2]-h[n-i]), cost[n-i+1] + abs(h[n-i+1]-h[n-i]));
	}
	cout << cost[0];

}
