#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll n,x, l,m,r, i1, i2, i3; cin >> n >> x;
	ll array[n], original[n];
	bool found = false;
	for (int i=0; i<n; i++) {
		cin >> array[i];
		original[i] = array[i];
	}
	if (n<3) cout << "IMPOSSIBLE";
	else {
		sort(array, array+n);
		ll left = 0, middle, right = n-1;
		for (middle = 1; middle < n-1; middle++) {
			left = 0; right = n-1;
			while (left < middle && middle < right) {
				if (array[left] + array[middle] + array[right] == x) {
					found = true;
					l = array[left]; m = array[middle]; r = array[right];
					break;
				}
				else if (array[left] + array[middle] + array[right] < x) {
					left++;
				}
				else {
					right--;
				}
			}
			if (found) {
				break;
			}
		}
		if (!found) cout << "IMPOSSIBLE";
		else {
			for (int i=0; i<n; i++) {
				if (original[i] == l) i1 = i;
			}
			for (int i=0; i<n; i++) {
				if (original[i] == m && i!= i1) i2 = i;
			}
			for (int i=0; i<n; i++) {
				if (original[i] == r && i!= i1 && i!= i2) i3 = i;
			}
			cout << i1+1 << " " << i2+1 << " " << i3+1;
		}
	}
}
