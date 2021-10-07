#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	int l, n, f, b; cin >> l >> n >> f >> b;
	vector<int> stops(n); map<int, int> tastiness;
	for (int i=0; i<n; i++) cin >> stops[i] >> tastiness[stops[i]];
	sort(stops.begin(), stops.end());
	vector<int> tastiest(n); tastiest[n-1] = n-1;
	for (int i=n-2; i>=0; i--) {
		if (tastiness[stops[i]] >= tastiness[stops[tastiest[i+1]]]) tastiest[i] = i;
		else tastiest[i] = tastiest[i+1];
	}
	ll answer = 0, diff = f-b; int index = -1, prevstop = 0;
	while (index != n-1) {
		answer += diff*(stops[tastiest[index+1]]-prevstop)*tastiness[stops[tastiest[index+1]]];
		index = tastiest[index+1];
		prevstop = stops[index];
	}
	cout << answer;
}
