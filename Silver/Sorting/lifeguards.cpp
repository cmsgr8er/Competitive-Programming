#include <bits/stdc++.h>
using namespace std;
//void setIO(string fileName = "") {
//    ios_base::sync_with_stdio(0); cin.tie(0);
//    if((int)fileName.size()) {
//        freopen((fileName+".in").c_str(), "r", stdin);
//        freopen((fileName+".out").c_str(), "w", stdout);
//    }
//}
int main() {
//	setIO("lifeguards");
	int workers = 0, mintime = 1e9, nobody = 0, n;
	cin >> n;
	vector<int> endpoints(2*n), alone(n);
	set<int> working;
	map<int, int> type; // 0 for start, 1 for end
	map<int, int> lifeguard;
	for (int i=0; i<n; i++) {
		cin >> endpoints[2*i] >> endpoints[2*i + 1];
		type[endpoints[2*i]] = 0;
		type[endpoints[2*i+1]] = 1;
		lifeguard[endpoints[2*i]] = i; lifeguard[endpoints[2*i+1]] = i;
	}
	sort(endpoints.begin(), endpoints.end());
	for (int i=0; i<2*n; i++) {
		if (type[endpoints[i]]==0) {
			workers++;
			working.insert(lifeguard[endpoints[i]]);
		}
		else if (type[endpoints[i]] == 1) {
			workers--;
			working.erase(working.find(lifeguard[endpoints[i]]));
		}
		if (workers == 0 && i<2*n-1) nobody += endpoints[i+1]-endpoints[i];
		if (workers == 1) {
			alone[*working.begin()] += endpoints[i+1]-endpoints[i];
		}
	}
	for (int i=0; i<n; i++) {
		mintime = min(mintime, alone[i]);
	}
	int total = endpoints[2*n-1] - endpoints[0] - nobody;
	cout << total - mintime;

}




