#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, vector<pair<int, int>>> blames;

bool cmp(const pair<int, int>& p, const pair<int, int>& q) {
	return p.second < q.second;
}

int totalblames(pair<int, int> point) {
	int total = 0;
	if (blames[point].size() == 0) {
		return 0;
	}
	else {
		for (auto p: blames[point]) {
			total += totalblames(p)+1;
		}
	}
	return total;
}

int main() {
	int n; cin >> n;
	vector<pair<int, int>> north, east;
	pair<int, int> allpoints[n];
	for (int i=0; i<n; i++) {
		char direction;
		int x,y;
		cin >> direction >> x >> y;
		allpoints[i] = {x,y};
		if (direction == 'N') north.push_back({x,y});
		else east.push_back({x,y});
	}
	sort(north.begin(), north.end());
	sort(east.begin(), east.end(), cmp);
	for (int i=0; i<north.size(); i++) {
		int j=0;
		while (j<east.size()) {
			if (north[i].first > east[j].first && north[i].second < east[j].second) {
				if (east[j].second - north[i].second < north[i].first - east[j].first) { // north wins
					blames[north[i]].push_back(east[j]);
					east.erase(east.begin() + j);
				}
				else if (east[j].second - north[i].second > north[i].first - east[j].first) { // east wins
					blames[east[j]].push_back(north[i]);
					break;
				}
				else { // tie
					j++;
				}
			}
			else j++;
		}
	}
	for (int i=0; i<n; i++) {
		cout << totalblames(allpoints[i]) << endl;
	}
}
