// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

vl psum(vl a) {
    vl psum(a.size() + 1);
    for (int i=0; i<a.size(); i++) psum[i+1] = psum[i] + a[i];
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
    setIO("hps");
    int N;
    long long answer =0;
    char choice;
    cin >> N;
    vl hoof(N+1), paper(N+1), scissors(N+1); // prefix sum vectors
    vl h(N), p(N), s(N); // tracks each result
    for (int i=0; i<N; i++) {
        cin >> choice;
        if (choice == 'H') h[i] = 0, p[i] = 1, s[i] = 0;
        else if (choice == 'P') s[i] = 1, h[i] = 0, p[i] = 0;
        else h[i] = 1, s[i] = 0, p[i] = 0;
    }
    hoof = psum(h), paper = psum(p), scissors = psum(s);
    for (int i=0; i<N+1; i++) {
        answer = max(answer, hoof[i] + scissors[N] - scissors[i]);
        answer = max(answer, hoof[i] + paper[N] - paper[i]);
        answer = max(answer, hoof[N]);
        answer = max(answer, scissors[i] + paper[N] - paper[i]);
        answer = max(answer, scissors[i] + hoof[N] - hoof[i]);
        answer = max(answer, scissors[N]);
        answer = max(answer, paper[i] + hoof[N] - hoof[i]);
        answer = max(answer, paper[i] + scissors[N] - scissors[i]);
        answer = max(answer, paper[N]);
    }
    cout << answer;
}
