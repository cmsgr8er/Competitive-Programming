#include <bits/stdc++.h>
using namespace std;
char table[52][52];
bool visited[52][52];
int N, M, great=0, bad = 0;
void floodfill(int r, int c) {
	visited[r][c] = true;
	if (r == 0 || r == N+1) return;
	if (c == 0 || c == M+1) return;
	if (table[r][c] == '#') return;
	if (table[r][c] == 'G') great++;
	if (table[r][c] == 'B') bad++;
	int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
	for (int i=0; i<4; i++) {
		if (table[r+dx[i]][c+dy[i]] != '#' && !visited[r+dx[i]][c+dy[i]]) {
			floodfill(r+dx[i], c+dy[i]);
		}
	}
}
int main() {
	int t, total, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
	cin >> t;
	for (int i=0; i<t; i++) {
		total=0, great = 0, bad = 0;
		cin >> N >> M;
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=M; j++) {
				cin >> table[i][j];
				if (table[i][j] == 'G') total++;
			}
		}
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=M; j++) {
				if (table[i][j] == 'B') {
					for (int k=0; k<4; k++) {
						if (table[i+dx[k]][j+dy[k]] == '.') table[i+dx[k]][j+dy[k]] = '#';
					}
				}
			}
		}
		floodfill(N,M);
		for (int i=0; i< N + 2; i++) {
			for (int j=0; j<M+2; j++) {
				visited[i][j] = false;
				table[i][j] = 'x';
			}
		}
		if (great == total && bad == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}



