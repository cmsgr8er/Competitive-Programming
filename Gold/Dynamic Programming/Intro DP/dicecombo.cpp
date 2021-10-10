#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m = 1e9+7; cin >> n;
	int dice[6] = {1,2,3,4,5,6}, answer[n+1]; answer[0] = 1;
	for (int i=1; i<=n; i++) {
        answer[i] = 0;
		for (auto c: dice) {
			if (i-c >=0) {
                answer[i] += answer[i-c];
                answer[i] = answer[i]%m;
            }
		}
	}
	cout << answer[n];
}
