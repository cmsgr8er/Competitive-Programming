#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K, L; cin >> N >> K >> L;
    vector<int> c(N); for (int i=0; i<N; i++) cin >> c[i];
    sort(c.begin(), c.end());
    int lo=0, hi=N, h;
    while (lo < hi) {
        h = (lo+hi+1)/2;
        bool atmostK = (c[N-h] >= h-K), atmostneeded;
        long long tot = 0;
        for (int i=1; i<=h; i++) {
            long long remainder = max(h-c[N-i], 0);
            tot += remainder;
        }
        atmostneeded = (tot <= K*L);
        if (atmostK && atmostneeded) lo = h;
        else hi = h-1;
    }
    cout << lo;
}
