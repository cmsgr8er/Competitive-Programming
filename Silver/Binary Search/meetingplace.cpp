#include <bits/stdc++.h>
using namespace std;
using ld = long double;
int n;
bool ok(vector<ld> x, vector<ld> v, ld time) {
	vector<ld> left, right;
	for (int i=0; i<n; i++) {
		left.push_back((ld)(x[i] - v[i]*time));
		right.push_back((ld)(x[i]+v[i]*time));
	}
	sort(left.begin(), left.end()); sort(right.begin(), right.end());
	return left[n-1] <= right[0];
}
int main() {
	cin >> n;
	vector<ld> pos(n), speed(n);
	for (int i=0; i<n; i++) cin >> pos[i];
	for (int i=0; i<n; i++) cin >> speed[i];
	ld left = 0, right = 1e18, ans;
	while (left < right) {
		ld middle = 0.5*left + 0.5*right;
		if (ok(pos, speed, middle)) {
			right = middle - 0.0000001;
			ans = middle;
		}
		else left = middle + 0.0000001;
	}
	// ok so apparently i needed to do this cout.precision shit which i dont get it but okay
	// thank u very cool usaco.guide. idk y this was a starred problem this was absolutely shit
	cout.precision(12); cout << ans;
}
