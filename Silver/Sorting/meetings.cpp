#include <bits/stdc++.h>
using namespace std;
int N, L; 
int ok(int t, vector<int> l, vector<int> r, vector<pair<int, int>> all) {
	int lefties = upper_bound(l.begin(), l.end(), t) - l.begin();
	int righties = r.end() - lower_bound(r.begin(), r.end(), L-t);
	int weight=0;
	for (int i=0; i<lefties; i++)  weight += all[i].second;
	for (int i=N-righties; i<N; i++) weight += all[i].second;
	return weight;
}

int main() {
	freopen("meetings.in", "r", stdin);
	freopen("meetings.out", "w", stdout);
	cin >> N >> L;
	vector<int> w(N), x(N), d(N);
	for (int i=0; i<N; i++) cin >> w[i] >> x[i] >> d[i];
	vector<int> lefts, rights;
	vector<pair<int, int>> all;
	int totalweight=0, halfweight;
	for (int i=0; i<N; i++) {
		totalweight += w[i];
		all.push_back({x[i], w[i]});
		if (d[i]==-1) lefts.push_back(x[i]);
		else rights.push_back(x[i]);
	}
	halfweight = (totalweight+1)/2;
	sort(lefts.begin(), lefts.end());
	sort(rights.begin(), rights.end());
	sort(all.begin(), all.end());
	int lo=1, hi=L, T;
	while (lo < hi) {
		T = (lo+hi)/2;
		// cout << T << " " << ok(T, lefts, rights, all) << endl;
		if (ok(T, lefts, rights, all) >= halfweight) hi = T;
		else lo = T+1;
	}
	T = lo;
	int answer =0;
	for (int i=0; i<lefts.size(); i++) {
		answer += lower_bound(rights.begin(), rights.end(), lefts[i]) - lower_bound(rights.begin(), rights.end(), lefts[i]-2*T);
	}
	cout << answer;
} 