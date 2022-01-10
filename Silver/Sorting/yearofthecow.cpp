#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin >> n >> k;
	set<int> intervals; 
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		intervals.insert(x/12+1);
	}
	long long answer = 12*intervals.size();
	intervals.insert(0);
	vector<int> gaps;
	for (auto it=intervals.begin(); it !=prev(intervals.end()); it++) {
		gaps.push_back(*next(it) - *it - 1);
	}
	sort(gaps.begin(), gaps.end());
	for (int i=0; i<gaps.size()-k+1; i++) answer += 12*gaps[i];
	cout << answer;
} 