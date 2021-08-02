#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

bool cmp(pair<ll, ll> a, pair<ll,ll> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("triangles");
	const ll mod = 1e9 + 7;
	ll N, answer = 0; cin >> N;
	vector<pair<ll,ll>> point(N);
	map<pair<ll, ll>, ll> wide, tall;
	for (int i=0; i<N; i++) {
		cin >> point[i].first >> point[i].second;
	}
	sort(point.begin(), point.end());
	vl nextX;
	nextX.push_back(0); nextX.push_back(N);
	for (int i=1; i<N; i++) {
		if (point[i].first != point[i-1].first) nextX.push_back(i);
	}
	sort(nextX.begin(), nextX.end());
	vl columnsum(N), height(N);
	for (int i=0; i<nextX.size()-1; i++) {
		columnsum[nextX[i]] = point[nextX[i]].second;
		for (int j=nextX[i]+1; j<nextX[i+1]; j++) {
			columnsum[j] = columnsum[j-1] + point[j].second;
		}
		for (int j=nextX[i]; j<nextX[i+1]; j++) {
			height[j] = (columnsum[nextX[i+1]-1] - 2*columnsum[j] + (2*j-nextX[i]-nextX[i+1]+2)*point[j].second)%mod;
			tall[point[j]] = height[j];
		}
	}
	sort(point.begin(), point.end(), cmp);
	vl nextY;
	nextY.push_back(0); nextY.push_back(N);
	for (int i=1; i<N; i++) {
		if (point[i].second != point[i-1].second) nextY.push_back(i);
	}
	sort(nextY.begin(), nextY.end());
	vl rowsum(N), length(N);
	for (int i=0; i<nextY.size()-1; i++) {
		rowsum[nextY[i]] = point[nextY[i]].first;
		for (int j=nextY[i]+1; j<nextY[i+1]; j++) {
			rowsum[j] = rowsum[j-1] + point[j].first;
		}
		for (int j=nextY[i]; j<nextY[i+1]; j++) {
			length[j] = (rowsum[nextY[i+1]-1] - 2*rowsum[j] + (2*j-nextY[i]-nextY[i+1]+2)*point[j].first)%mod;
			wide[point[j]] = length[j];
		}
	}
	for (int i=0; i<N; i++) {
		answer = (answer + (wide[point[i]]*tall[point[i]]))%mod;
	}
	cout << answer;
}
