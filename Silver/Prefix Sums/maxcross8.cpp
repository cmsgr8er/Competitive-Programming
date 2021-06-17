// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

vl psum(vl a) {
    vl psum(a.size() + 1);
    for (int i=0; i<a.size(); i++) {
        psum[i+1] = psum[i] + a[i];
    }
    return psum;
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("maxcross");
    int N, K, B, answer = 1e6;
    long long possible;
    cin >> N >> K >> B;
    vl id(N), p, broken(B+2);
    for (int i=0; i<N; i++) {
        id[i] = 1;
    }
    broken[0] = 0;
    for (int i=1; i<B+1; i++) {
        cin >> broken[i];
        id[broken[i]-1] = 0;
    }
    broken[B+1] = N;
    sort(broken.begin(), broken.end());
    p = psum(id);
    for (int i=0; i<B+1; i++) {
        for (int j=i+1; j<B+2; j++) {
            possible = p[broken[j]] - p[broken[i]] + j-i-1;
            if (possible >= K) {
                answer = min(answer, j-i-1);
            }
        }

    }
    if (answer == 1e6) {
        answer = B;
    }
    cout << answer;
}
