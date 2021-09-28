#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,n; cin >> x >> n;
	long long cost = 0;
	multiset<int> sticks;
	for (int i=0; i<n; i++) {
		int y; cin >> y; sticks.insert(y);
	}
	while (sticks.size() > 1) {
		int sum = *sticks.begin() + *next(sticks.begin());
		sticks.erase(sticks.begin()); sticks.erase(sticks.begin());
		sticks.insert(sum);
		cost += sum;
	}
	cout << cost;
}
