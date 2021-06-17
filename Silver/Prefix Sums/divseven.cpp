// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

vl psum(vl a) {
    vl psum(a.size() + 1);
    for (int i=0; i< a.size(); i++) {
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
    setIO("div7");
    int answer = 0, N, smallest = 1e5, largest = 0;
    cin >> N;
    vl id(N);
    for (int i=0; i<N; i++) {
        cin >> id[i];
    }
    vl p = psum(id);
    for (int i=0; i<N+1; i++) {
        p[i] = p[i]%7;
    }
    for (int i=0; i<7; i++) {
        smallest = 1e5, largest = 0;
        for (int j=0; j<N+1; j++) {
            if (p[j] == i) {
                smallest = min(smallest, j);
                largest = max(largest, j);
                answer = max(answer, largest - smallest);
            }
        }
    }
    cout << answer;

}
