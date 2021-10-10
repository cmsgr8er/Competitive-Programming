#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
    int answer[n+1]; answer[0] = 0;
    for (int i=1; i<=n; i++) {
        answer[i] = 2147483646;
        vector<int> digits;
        int m = i;
        while (m > 0) {
            digits.push_back(m%(10));
            m /= 10;
        }
        for (auto j: digits) answer[i] = min(answer[i], 1 + answer[i-j]);
        digits.clear();
    }
    cout << answer[n];
}
