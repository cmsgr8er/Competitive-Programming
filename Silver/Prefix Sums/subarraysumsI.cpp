#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll n,x; cin >> n >> x;
	ll array[n], sum = 0, answer = 0;
	map<ll, ll> psum;
	psum[0]++;
	for (int i=0; i<n; i++) {
		cin >> array[i];
	}
	for (int i=0; i<n; i++) {
		sum += array[i];
		answer += psum[sum-x];
		psum[sum]++;
	}
	cout << answer;

}
