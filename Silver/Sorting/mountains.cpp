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
	setIO("mountains");
	int N, x, y, right = -1e9, answer = 0; cin >> N;
	int start[N];
	map<int, int> end;
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		start[i] = x-y; end[start[i]] = x+y;
	}
	sort(start, start+N);
	for (int i=0; i<N; i++) {
		if (end[start[i]] > right) {
			answer++;
			right = end[start[i]];
		}
	}
	cout << answer;
}
