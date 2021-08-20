#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, end = 0, f = 0, a, d; cin >> n;
	vector<long long> duration(n), deadline(n);
	for (int i=0; i<n; i++) {
		cin >> a >> d;
		duration[i] = a; deadline[i] = d;
	}
	sort(duration.begin(), duration.end()); sort(deadline.begin(), deadline.end());
	for (int i=0; i<n; i++) {
		end += deadline[i];
		f += (n-i)*duration[i];
	}
	cout << end - f;
}
