#include <bits/stdc++.h>
using namespace std;
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("pairup");
	int N, answer = 0; cin >> N;
	vector<pair<int, int>> cows(N);
	vector<int> x(N), output(N), forward(N), reverse(N);
	for (int i=0; i<N; i++) {
		cin >> cows[i].second >> cows[i].first;
	}
	sort(cows.begin(), cows.end());
	for (int i=0; i<N; i++) {
		output[i] = cows[i].first;
		x[i] = cows[i].second;
	}
	forward[0] = x[0]; reverse[0] = x[N-1];
	for (int i=1; i<N; i++) {
		forward[i] = forward[i-1] + x[i];
		reverse[i] = reverse[i-1] + x[N-1-i];
	}
	for (int i=0; i<N; i++) {
		int index = lower_bound(reverse.begin(), reverse.end(), forward[i]) - reverse.begin();
		answer = max(answer, output[i] + output[N-1-index]);
		index = lower_bound(forward.begin(), forward.end(), reverse[i]) - forward.begin();
		answer = max(answer, output[index] + output[N-1-i]);
	}
	cout << answer;
}
