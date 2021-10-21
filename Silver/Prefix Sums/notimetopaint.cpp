#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q; cin >> n >> q;
    char color[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<char> fence(n);
    for (int i=0; i<n; i++) cin >> fence[i];
    map<char, int> lastpos, firstpos; 
    int strokes[n], rstrokes[n];
    strokes[0] = 1; lastpos[fence[0]] = 1;
    for (int i=1; i<n; i++) {
        strokes[i] = strokes[i-1];
        int j=0; bool needpaint = false;
        while (color[j] != fence[i]) {
            if (lastpos[color[j]] >= lastpos[fence[i]]) needpaint = true;
            j++;
        }
        if (needpaint || (fence[i] == 'A' && lastpos['A'] == 0)) strokes[i]++;
        lastpos[fence[i]] = i+1;
    }
    for (int i=0; i<26; i++) firstpos[color[i]] = n+1;
    firstpos[fence[n-1]] = n; rstrokes[n-1] = 1;
    for (int i=n-2; i>=0; i--) {
        rstrokes[i] = rstrokes[i+1];
        int j=0; bool needpaint = false;
        while (color[j] != fence[i]) {
            if (firstpos[color[j]] <= firstpos[fence[i]]) needpaint = true;
            j++;
        }
        if (needpaint || (fence[i] == 'A' && firstpos['A'] == n+1)) rstrokes[i]++;
        firstpos[fence[i]] = i+1;
    }
    for (int i=0; i<q; i++) {
        int a,b, left, right; cin >> a >> b;
        a -= 2; 
        if (a>=0) left = strokes[a];
        else left = 0;
        if (b < n) right = rstrokes[b];
        else right = 0;
        cout << left + right << endl;
    }
}
