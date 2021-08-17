#include <bits/stdc++.h>
using namespace std;
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
struct cow {
	int a, t, i;
};

int main() {
	setIO("convention2");
	int n, answer = 0; cin >> n;
	vector<int> time(n);
	set<int> arrival;
	priority_queue<int> waiting;
	map<int, vector<int>> scheduled;
	vector<cow> moo;
	for (int i=0; i<n; i++) {
		int a,t; cin >> a >> t;
		arrival.insert(a);
		scheduled[a].push_back(i);
		moo.push_back({a,t,i});
	}
	sort(scheduled[*arrival.begin()].begin(), scheduled[*arrival.begin()].end());
	int eating = scheduled[*arrival.begin()][0];
	for (auto it=arrival.begin(); it != arrival.end(); it++) { // arrival indices
		if (*it > moo[eating].a + moo[eating].t) {
			time[-waiting.top()] = max(moo[eating].a + moo[eating].t - moo[-waiting.top()].a, 0);
			moo[-waiting.top()].a = max(moo[-waiting.top()].a, moo[eating].a + moo[eating].t);
			eating = -waiting.top(); waiting.pop();
		}
		for (int j=0; j< scheduled[*it].size(); j++) {
			if (scheduled[*it][j] != eating) waiting.push(-scheduled[*it][j]);
		}
	}
	for (int i=0; i<n; i++) {
		answer = max(answer, time[i]);
	}
	cout << answer;
}
