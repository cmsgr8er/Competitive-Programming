#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

bool cmp(pair<ll, ll> p, pair<ll, ll> q) {
	return p.second < q.second;
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("split");
	ll n, totalarea, smallarea, answer; cin >> n;
	vector<pair<ll, ll>> points(n);
	for (int i=0; i<n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	sort(points.begin(), points.end());
	vl ymax(n), rymax(n), ymin(n), rymin(n), xmax(n), rxmax(n), xmin(n), rxmin(n);
	ymax[0] = points[0].second; ymin[0] = points[0].second;
	rymax[0] = points[n-1].second; rymin[0] = points[n-1].second;
	for (int i=0; i<n-1; i++) {
		ymax[i+1] = max(ymax[i], points[i+1].second);
		rymax[i+1] = max(rymax[i], points[n-2-i].second);
		ymin[i+1] = min(ymin[i], points[i+1].second);
		rymin[i+1] = min(rymin[i], points[n-2-i].second);
	}
	for (int i=0; i<n-1; i++) {
		smallarea = min(smallarea, (points[i].first-points[0].first)*(ymax[i] - ymin[i]) +
				(points[n-1].first - points[i+1].first)*(rymax[n-2-i] - rymin[n-2-i]));
	}
	sort(points.begin(), points.end(), cmp);
	xmax[0] = points[0].first; xmin[0] = points[0].first;
	rxmax[0] = points[n-1].first; rxmin[0] = points[n-1].first;
	for (int i=0; i<n-1; i++) {
		xmax[i+1] = max(xmax[i], points[i+1].first);
		rxmax[i+1] = max(rxmax[i], points[n-2-i].first);
		xmin[i+1] = min(xmin[i], points[i+1].first);
		rxmin[i+1] = min(rxmin[i], points[n-2-i].first);
	}
	for (int i=0; i<n-1; i++) {
		smallarea = min(smallarea, (points[i].second-points[0].second)*(xmax[i] - xmin[i]) +
				(points[n-1].second - points[i+1].second)*(rxmax[n-2-i] - rxmin[n-2-i]));
	}
	totalarea = (xmax[n-1] - xmin[n-1])*(ymax[n-1] - ymin[n-1]);
	answer = totalarea - smallarea;
	cout << answer;

}
