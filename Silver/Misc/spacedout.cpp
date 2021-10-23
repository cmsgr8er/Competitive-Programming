#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int beauty[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> beauty[i][j];
        }
    }
    int hor =0, vert =0;
    for (int i=0; i<n; i++) {
        int c1=0, c2=0;
        for (int j=0; j<n; j+=2) c1 += beauty[i][j];
        for (int j=1; j<n; j+=2) c2 += beauty[i][j];
        vert += max(c1, c2);
    }
    for (int j=0; j<n; j++) {
        int r1=0, r2=0;
        for (int i=0; i<n; i+=2) r1 += beauty[i][j];
        for (int i=1; i<n; i+=2) r2 += beauty[i][j];
        hor += max(r1, r2);
    }
    cout << max(hor, vert);
}
