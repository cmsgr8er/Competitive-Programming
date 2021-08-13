#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	multiset<int> left, dist;
	string s; cin >> s;
	vector<int> segment(s.size()+2);
	for (int i=0; i<s.size(); i++) {
		segment[i] = s[i] - '0';
	}
	int n = s.size();
	left.insert(0);
	for (int i=1; i<n; i++) {
		if (segment[i] != segment[i-1]) left.insert(i);
	}
	left.insert(n);
	auto copy = left.begin();
	for (auto it = left.begin(); it != --left.end(); it++) {
		copy++;
		dist.insert(*copy - *it);
	}
	int m; cin >> m;
	for (int i=0; i<m; i++) {
		int x; cin >> x; x--;
		auto l = left.lower_bound(x), r = left.upper_bound(x);
		if (x == 0) {
			if (segment[1] == segment[0]) {
				dist.erase(dist.find(*r));
				dist.insert(1); dist.insert(*r-1);
				left.insert(1);
			}
			else {
				auto rcopy = r; rcopy++;
				dist.erase(dist.find(1)); dist.erase(dist.find(*rcopy - 1));
				dist.insert(*rcopy);
				left.insert(0); left.erase(left.find(1));
			}
			segment[0] = 1-segment[0];
		}
		else if (x == n-1) {
			if (segment[n-2] == segment[n-1]) {
				auto lcopy = l; lcopy--;
				dist.erase(dist.find(n-*lcopy));
				dist.insert(1); dist.insert(n-*lcopy-1);
				left.insert(n-1);
			}
			else {
				auto lcopy = l; lcopy--;
				dist.erase(dist.find(n-1-*lcopy)); dist.erase(dist.find(1));
				dist.insert(n-*lcopy);
				left.erase(left.find(n-1));
			}
			segment[n-1] = 1-segment[n-1];
		}
		else if (segment[x-1] == segment[x] && segment[x] == segment[x+1]) {
			auto lcopy = l; lcopy--;
			dist.erase(dist.find(*r-*lcopy));
			dist.insert(x - *lcopy); dist.insert(1); dist.insert(*r-x-1);
			left.insert(x); left.insert(x+1);
			segment[x] = 1-segment[x];
		}
		else if (segment[x-1] == segment[x] && segment[x] != segment[x+1]) {
			auto rcopy = r, lcopy = l; rcopy++; lcopy--;
			dist.erase(dist.find(*rcopy-*r)); dist.erase(dist.find(*r - *lcopy));
			dist.insert(*r-*lcopy-1); dist.insert(*rcopy-x);
			left.insert(x); left.erase(left.find(x+1));
			segment[x] = 1-segment[x];
		}
		else if (segment[x-1] != segment[x] && segment[x] == segment[x+1]) {
			auto lcopy = l; lcopy--;
			dist.erase(dist.find(*r-*l)); dist.erase(dist.find(x - *lcopy));
			dist.insert(*r-*l-1); dist.insert(x-*lcopy + 1);
			left.insert(x+1); left.erase(left.find(x));
			segment[x] = 1-segment[x];
		}
		else if (segment[x-1] != segment[x] && segment[x] != segment[x+1]) {
			auto lcopy = l, rcopy = r; lcopy--; rcopy++;
			dist.erase(dist.find(x-*lcopy)); dist.erase(dist.find(*rcopy-x-1)); dist.erase(dist.find(1));
			dist.insert(*rcopy - *lcopy);
			left.erase(left.find(x)); left.erase(left.find(x+1));
			segment[x] = 1-segment[x];
		}
//		for (auto it = dist.begin(); it != dist.end(); it++) {
//			cout << *it << " ";
//		}
//		for (int i=0; i<n; i++) {
//			cout << segment[i];
//		}
//		cout << ": ";
		cout << *dist.rbegin() << " ";
	}
}
