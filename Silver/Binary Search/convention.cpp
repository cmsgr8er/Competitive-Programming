#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int> a, int m, int c, int time) {
	int bus = 1, start = 0, end = 0;
	while (bus <= m && end < a.size()) {
		if (end-start == c || a[end]-a[start] > time) {
			start = end; bus++;
		}
		else end++;
	}
	return end == a.size();
}

int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	int N,M,C; cin >> N >> M >> C;
	vector<int> arrival(N);
	for (int i=0; i<N; i++) cin >> arrival[i];
	sort(arrival.begin(), arrival.end());
	int left = 0, right = 1e9;
	while (left < right) {
		int middle = (left + right)/2;
		if (ok(arrival, M, C, middle)) right = middle;
		else left = middle+1;
	}
	cout << left;
}
