#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int n, answer = 0; cin >> n;
	pair<int, int> array[n];
	for (int i=0; i<n; i++) {
		int value; cin >> value;
		array[i] = {value, i};
	}
	sort(array, array+n);
	for (int i=0; i<n; i++) {
		answer = max(answer, array[i].second - i);
	}
	cout << answer+1;
}
