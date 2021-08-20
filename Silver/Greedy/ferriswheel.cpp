#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n,x, answer = 0; cin >> n >> x;
	vector<int> w(n);
	for (int i=0; i<n; i++) cin >> w[i];
	sort(w.begin(), w.end());
	int left = 0, right = n-1;
	while (left < right) {
		answer++;
		if (w[left] + w[right] <=x) {
			left++;
			right--;
		}
		else {
			right--;
		}
	}
	if (left == right) answer++;
	cout << answer;
}
