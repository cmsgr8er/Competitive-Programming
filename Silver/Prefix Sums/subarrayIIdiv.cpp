#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	map<int, int> residues;
	residues[0] = 1;
	long long psum = 0, answer = 0;
	for (int x: a) {
		psum += (n + (x%n))%n;
		answer += residues[psum%n];
		residues[psum%n]++;
	}
	cout << answer;
}




