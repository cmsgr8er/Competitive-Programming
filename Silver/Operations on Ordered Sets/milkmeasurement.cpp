#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	int n,g, answer = 0; cin >> n >> g;
	multiset<int> cows;
	map<int, int> output;
	for (int i=0; i<n; i++) {
		cows.insert(g);
	}
	vector<pair<pair<int, int>, int>> logs(n);
	for (int i=0; i<n; i++) {
		int day, id, amt; cin >> day >> id >> amt;
		logs[i] = {{day, id}, amt};
		output[id] = g;
	}
	sort(logs.begin(), logs.end());
	for (int i=0; i<n; i++) {
		int num = logs[i].first.second, add = logs[i].second;
		if (output[num] == *prev(cows.end())) {
			if (*prev(cows.end()) != *prev(prev(cows.end()))) {
				if (output[num] + add <= *prev(prev(cows.end()))) answer++;
			}
			else answer++;
		}
		else {
			if (output[num] + add >= *prev(cows.end())) answer++;
		}
		cows.erase(cows.find(output[num])); cows.insert(output[num] + add);
//		for (auto it = cows.begin(); it != cows.end(); it++) {
//			cout << *it << " ";
//		}
		output[num] += add;
//		cout << endl;
	}
	cout << answer;
}
