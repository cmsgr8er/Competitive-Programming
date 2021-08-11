#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, n; cin >> x >> n;
	multiset<int> lights, distance;
	lights.insert(0); lights.insert(x);
	distance.insert(x);
	for (int i=0; i<n; i++) {
		int k; cin >> k;
		lights.insert(k);
		auto r = lights.upper_bound(k), copy = r;
		--copy; --copy; auto l = copy;
		distance.erase(distance.lower_bound(*r - *l));
		distance.insert(k - *l); distance.insert(*r - k);
		cout << *distance.rbegin() << " ";
	}
}
