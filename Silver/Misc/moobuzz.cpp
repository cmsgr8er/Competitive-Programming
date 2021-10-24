#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    long long n; cin >> n;
    long long answer = 15*(n-2)/8;
    while (answer <= 15*(n+1)/8) {
        if (answer%3 != 0 && answer%5 != 0 && answer - answer/3 - answer/5 + answer/15 == n) {
            break;
        }
        else answer++;
    }
    cout << answer;
}
