#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) {
	if (m == 0) return n;
	if (n == 0) return m;
	if (m==n) return n;
	if (n > m) return gcd(n%m, m);
	return gcd(n, m%n);
}

int main() {
	int n, answer = 0;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	int L[n], R[n];
	L[0] = a[0], R[0] = a[n-1];
	for (int i=1; i<n; i++) {
		L[i] = gcd(L[i-1], a[i]);
		R[i] = gcd(R[i-1], a[n-1-i]);
	}
	for (int i=1; i<n-1; i++) {
		answer = max(answer, gcd(L[i-1], R[n-2-i]));
	}
	answer = max(answer, R[n-2]);
	answer = max(answer, L[n-2]);
	cout << answer;
}
