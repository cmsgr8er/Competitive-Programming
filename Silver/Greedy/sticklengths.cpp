#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	long long answer = 0;
	vector<int> array(n);
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		array[i] = x;
	}
	sort(array.begin(), array.end());
	int median = array[n/2];
	for (int i=0; i<n; i++) {
		answer += abs(median - array[i]);
	}
	cout << answer;
}
