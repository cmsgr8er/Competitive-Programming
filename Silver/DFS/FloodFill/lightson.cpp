#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[102][102];
bool connected[102][102], visited[102][102];
int N, M, answer = 0;
void toggle(int r, int c) {
	for (auto pair: adj[r][c]) {
		if (!connected[get<0>(pair)][get<1>(pair)]) {
			connected[get<0>(pair)][get<1>(pair)] = true;
			answer++;
		}
	}
}
void floodfill(int r, int c) {
	visited[r][c] = true;
	if (r == 0 || r== N+1 || c ==0 || c== N+1) return; // out of bounds
	toggle(r,c);
	int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
	for (int i=0; i<4; i++) {
		if (!visited[r+dx[i]][c+dy[i]] && connected[r+dx[i]][c+dy[i]]) {
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
	setIO("lightson");
	int x,y,a,b;
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> x >> y >> a >> b;
		adj[x][y].push_back({a,b});
	}
	int z = -1;
	while (z != answer) {
		z = answer;
		floodfill(1,1);
		for (int i=0; i<N+2; i++) {
			for (int j=0; j<N+2; j++) {
				visited[i][j] = false;
			}
		}
	}
	if (connected[1][1]) cout << answer;
	else cout << answer + 1;
}




