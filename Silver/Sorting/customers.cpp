#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, counter = 0, answer = 0; cin >> n;
	vector<int> times(2*n);
	map<int, int> tell;
	for (int i=0; i<n; i++) {
		cin >> times[2*i] >> times[2*i+1];
		tell[times[2*i]] = 0; tell[times[2*i+1]] = 1;
	}
	sort(times.begin(), times.end());
	for (int i=0; i<2*n; i++) {
		if (tell[times[i]] == 0) counter++;
		else counter--;
		answer = max(answer, counter);
	}
	cout << answer;

}



