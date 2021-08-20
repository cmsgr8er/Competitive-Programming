#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k, answer = 0; cin >> n >> m >> k;
	vector<int> applicants(n), apartments(m);
	for (int i=0; i<n; i++) {
		cin >> applicants[i];
	}
	for (int i=0; i<m; i++) {
		cin >> apartments[i];
	}
	sort(applicants.begin(), applicants.end()); sort(apartments.begin(), apartments.end());
	int left = 0;
	for (int i=0; i<n; i++) {
		while (left < m && apartments[left] < applicants[i]-k) left++;
		if (left < m && apartments[left] <= applicants[i] +k) {
			answer++;
			left++;
		}
	}
	cout << answer;
}
