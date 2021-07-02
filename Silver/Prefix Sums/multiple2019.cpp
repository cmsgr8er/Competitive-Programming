#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int l = s.length();
	map<int, int> residues;
	residues[0] = 1;
	int digits[l], a[l], b[l], answer = 0, factor = 202;
	for (int i=0; i<s.length(); i++) {
		digits[i] = s.at(i) - '0';
	}
	a[0] = digits[0], b[0] = digits[0];
	for (int i=1; i<s.length(); i++) {
		a[i] = (10*a[i-1] + digits[i])%2019;
		b[i] = (factor*a[i])%2019;
		factor = (factor*202)%2019;
	}
	for (int i=0; i<l; i++) {
		answer += residues[b[i]];
		residues[b[i]]++;
	}
	cout << answer;
}
