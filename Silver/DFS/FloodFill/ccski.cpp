#include<bits/stdc++.h>
using namespace std;
int grid[502][502];
bool visited[502][502], waypoint[502][502];
int N, M, D, reached = 0;
void floodfill(int r, int c) {
	visited[r][c] = true;
	if (waypoint[r][c]) reached++;
	if (r == 0 || r == M+1) return;
	if (c==0 || c == N+1) return;
	int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
	for (int i=0; i<4; i++) {
		if (!visited[r+dx[i]][c+dy[i]] && abs(grid[r+dx[i]][c+dy[i]] - grid[r][c]) <= D) {
			floodfill(r+dx[i], c+dy[i]);
		}
	}
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("ccski");
	int x,y, total=0;
	cin >> M >> N;
	for (int i=1; i<=M; i++) {
		for (int j=1; j<=N; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i=1; i<=M; i++) {
		for (int j=1; j<=N; j++) {
			cin >> waypoint[i][j];
			if (waypoint[i][j]) x=i, y=j, total++;
		}
	}
	int left = 0, right = 1e9;
	while (left < right) {
		D = (left + right)/2;
		floodfill(x,y);
		if (reached == total) right = D;
		else left = D+1;
		reached = 0;
		for (int i=0; i<M+2; i++) {
			for (int j=0; j<N+2; j++) {
				visited[i][j] = false;
			}
		}
	}
	cout << left;
}



