#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t; cin >> n >> t;
	int time[n];
	for (int i=0; i<n; i++) {
		cin >> time[i];
	}
	int left = 0, right = 0, sum = time[0], answer = 0;
	while (left <= right && right < n) {
		if (sum <= t) {
			answer = max(answer, right-left+1);
			right++;
			sum += time[right];
		}
		else if (sum > t) {
			sum -= time[left];
			if (left == right) {
				right++;
				sum += time[right];
			}
			left++;
		}
	}
	cout << answer;

}
