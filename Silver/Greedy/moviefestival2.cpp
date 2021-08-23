#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin >> n >> k;
	vector<pair<int,int>> movies(n);
	vector<int> watching;
	for (int i=0; i<n; i++) {
		int start, end; cin >> start >> end;
		movies[i] = {end, start};
	}
	sort(movies.begin(), movies.end());
	int answer = 1;
	watching.push_back(movies[0].first);
	for (int i=1; i<n; i++) {
		if (movies[i].second >= watching[0]) {
			answer++;
			watching.erase(prev(upper_bound(watching.begin(), watching.end(), movies[i].second)));
			watching.push_back(movies[i].first);
		}
		else if (watching.size() < k) {
			answer++;
			watching.push_back(movies[i].first);
		}
	}
	cout << answer;
}
