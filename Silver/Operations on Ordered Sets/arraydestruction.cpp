#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n; cin >> t;
	vector<pair<int,int>> partition;
	vector<int> array, copy;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		for (int i=0; i<2*n; i++) {
			int element; cin >> element;
			array.push_back(element);
		}
		int bad = 0;
		sort(array.begin(), array.end());
		for (int i=0; i<2*n-1; i++) {
			for (int j=0; j<2*n; j++) copy.push_back(array[j]);
			int target = copy[2*n-1], orig = copy[2*n-1] + copy[i], end, it;
			partition.push_back({copy[i], copy[2*n-1]});
			copy.erase(copy.begin() + i); copy.erase(prev(copy.end()));
			while (copy.size() > 0) {
				end = copy[copy.size()-1];
				copy.erase(prev(copy.end()));
				it = lower_bound(copy.begin(), copy.end(), target - end) - copy.begin();
				if (copy[it] == target - end && it < copy.size()) {
					partition.push_back({copy[it], end});
					copy.erase(lower_bound(copy.begin(), copy.end(), target - end));
					target = end;
				}
				else break;
			}
			if (partition.size() == n) {
				cout << "YES" << endl << orig << endl;
				for (int k=0; k<n; k++) {
					cout << partition[k].first << " " << partition[k].second << endl;
				}
				break;
			}
			else bad++;
			copy.clear(); partition.clear();
		}
		if (bad == 2*n-1) cout << "NO" << endl;
		array.clear(); copy.clear(); partition.clear();
	}
}
