#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll t, n; cin >> t;
	for (int p=0; p<t; p++) {
		ll largest = 0;
		cin >> n;
		set<ll> d;
		vector<ll> array;
		bool works = true, symmetric = true;
		for (int i=0; i<2*n; i++) {
			ll x; cin >> x;
			d.insert(x);
			array.push_back(x);
		}
		sort(array.begin(), array.end());
		for (int i=0; i<n; i++) {
			if (array[2*i] != array[2*i+1]) symmetric = false;
			if (i<n-1 && array[2*i+1] == array[2*i+2]) symmetric = false;
		}
		if (symmetric) {
			vector<ll> D = vector<ll> (d.begin(), d.end());
			vector<ll> differences(n-1);
			for (int i=0; i<n-1; i++) {
				differences[i] = D[i+1]-D[i];
			}
			for (int i=0; i<n-1; i++) {
				if (differences[i]%(2*(i+1)) == 0) {
					differences[i] /= 2*(i+1);
				}
				else {
					works = false;
					cout << "NO";
					break;
				}
			}
			if (works) {
				for (int i=0; i<n-1; i++) {
					largest += differences[i];
				}
				if (D[n-1]%(2*n) == 0) {
					if (largest < D[n-1]/(2*n)) cout << "YES";
					else cout << "NO";
				}
				else cout << "NO";
			}
			d.clear(), D.clear(), differences.clear();
		}
		else cout << "NO";
		cout << endl;
	}
}
