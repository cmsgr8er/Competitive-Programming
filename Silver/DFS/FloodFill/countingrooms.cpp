// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;
int m,n;
bool table[MN][MN];
char grid[MN][MN];

void ff(int r, int c) {
    if (r<1 || r>n || c<1 || c>m) return;
    table[r][c] = true;
    int dx[4] = {0,1,-1,0}, dy[4] = {1,0,0,-1};
    for (int i=0; i<4; i++) {
        if (grid[r+dx[i]][c+dy[i]] == '.' && !table[r+dx[i]][c+dy[i]]) {
            ff(r+dx[i], c+dy[i]);
        }
    }
}

int main() {
    int answer = 0;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!table[i][j] && grid[i][j] == '.') {
                answer++;
                ff(i,j);
            }
        }
    }
    cout << answer;
}
