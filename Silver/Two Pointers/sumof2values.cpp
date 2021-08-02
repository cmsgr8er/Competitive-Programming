#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x, counter=0, v1, v2, i1, i2; cin >> n >> x;
	vector<int> array(n), original(n);
	for (int i=0; i<n; i++) {
		cin >> array[i];
		original[i] = array[i];
	}
	sort(array.begin(), array.end());
	for (int i=0; i<n; i++) {
		int corresponding = lower_bound(array.begin(), array.end(), x-array[i])-array.begin();
		if (array[corresponding] == x-array[i] && corresponding != i) {
			v1 = array[i]; v2 = array[corresponding];
			break;
		}
		else counter++;
	}
	if (counter == n) cout << "IMPOSSIBLE";
	else {
		for (int i=0; i<n; i++) {
			if (original[i] == v1) {
				i1 = i;
				break;
			}
		}
		for (int i=0; i<n; i++) {
			if (original[i] == v2 && i != i1) {
				i2 = i;
				break;
			}
		}
		cout << i1+1 << " " << i2+1;
	}
}
