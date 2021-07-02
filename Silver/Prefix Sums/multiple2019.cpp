/* Key idea is the following:
 *
 * Note that if a given string of digits forms a multiple of 2019,
 * lets say the number is d_k + 10*d_{k+1} + 100*d_{k+2} + ... + 10^(n-k)d_n
 * then we can multiply by 10^(k-1).
 *
 * If we define S_n to be the number formed by the first n digits, then after
 * multiplying the above expression by 10^(k-1), it is equivalent to
 *
 * S_n - S_{k-1} = 0 (mod 2019) <=> S_n = S_{k-1} (mod 2019)
 *
 * Note that it was key that gcd(2019, 10) = 1. Thus, 10^(-1) = 202 (mod 2019)
 * and so we can multiply subsequent terms by a factor of 202 to form an
 * equivalent sequence for S_n in the field F_{2019}.
 *
 * Then it just simply remains to find the number of such pairs of S_n with equal
 * residues, which is an easy exercise.
 */
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




