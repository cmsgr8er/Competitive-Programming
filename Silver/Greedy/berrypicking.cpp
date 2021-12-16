#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
	int n,k, hi=0, answer = 0, sum = 0; cin >> n >> k;
	vector<int> b(n); 
	for (int i=0; i<n; i++) {
		cin >> b[i];
		hi = max(hi, b[i]);
		sum += b[i];
	}
	sort(b.rbegin(), b.rend());
	for (int m=1; m<=min(hi,sum/k+1); m++) {
		int berries = 0, baskets = 0;
		vector<int> amounts, rem;
		for (int i=0; i<n; i++) rem.push_back(b[i]%m);
		sort(rem.rbegin(), rem.rend());
		for (int i=0; i<n; i++) baskets += min(b[i]/m, k-baskets);
		for (int i=0; i<baskets; i++) amounts.push_back(m);
		for (int i=0; i<k-baskets; i++) amounts.push_back(rem[i]);
		sort(amounts.begin(), amounts.end());
		for (int i=0; i<k/2; i++) berries += amounts[i];
		answer = max(answer, berries);
		amounts.clear(); rem.clear();
	}
	cout << answer;
} 
