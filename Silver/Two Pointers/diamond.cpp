#include <bits/stdc++.h>
using namespace std;
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("diamond");
	int n,k, answer = 0; cin >> n >> k;
	vector<int> diamond(n);
	for (int i=0; i<n; i++) {
		cin >> diamond[i];
	}
	sort(diamond.begin(), diamond.end());
	vector<int> left(n), right(n), maxleft(n), maxright(n);
	for (int i=0; i<n; i++) {
		int l = lower_bound(diamond.begin(), diamond.end(), diamond[i]-k) - diamond.begin();
		left[i] = i-l+1;
	}
	for (int i=n-1; i>=0; i--) {
		int r = lower_bound(diamond.begin(), diamond.end(), diamond[i]+k+1)-diamond.begin();
		right[i] = r - i;
	}
	maxleft[0] = left[0]; maxright[n-1] = right[n-1];
	for (int i=1; i<n; i++) {
		maxleft[i] = max(maxleft[i-1], left[i]);
	}
	for (int i=n-2; i>=0; i--) {
		maxright[i] = max(maxright[i+1], right[i]);
	}
	for (int i=0; i<n-1; i++) {
		answer = max(answer, maxleft[i] + maxright[i+1]);
	}
	cout << answer;
}
