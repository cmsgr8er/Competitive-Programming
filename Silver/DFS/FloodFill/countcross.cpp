#include <bits/stdc++.h>
using namespace std;
bool visited[102][102], cow[102][102];
vector<pair<int, int>> adj[102][102];
int N, pairs = 0;
void floodfill(int r, int c) {
	visited[r][c] = true;
	if (r==0||r==N+1||c==0||c==N+1) return;
	for (auto u: adj[r][c]) {
		if (!visited[get<0>(u)][get<1>(u)]) {
			if (cow[get<0>(u)][get<1>(u)]) pairs++;
			floodfill(get<0>(u), get<1>(u));
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
	setIO("countcross");
	int K, R, dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0},x,y,a,b;
	cin >> N >> K >> R;
	int r[K], c[K];
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			for (int k=0; k<4; k++) {
				adj[i][j].push_back({i+dx[k], j+dy[k]});
			}
		}
	}
	for (int i=0; i<R; i++) {
		cin >> x >> y >> a >> b;
		for (int j=0; j<4; j++) {
			if (get<0>(adj[x][y][j]) == a && get<1>(adj[x][y][j]) == b) {
				adj[x][y].erase(adj[x][y].begin() + j); break;
			}
		}
		for (int j=0; j<4; j++) {
			if (get<0>(adj[a][b][j]) == x && get<1>(adj[a][b][j]) == y) {
					adj[a][b].erase(adj[a][b].begin() + j); break;
			}
		}
	}
	for (int i=0; i<K; i++) {
		cin >> r[i] >> c[i];
		cow[r[i]][c[i]] = true;
	}
	for (int i=0; i<K; i++) {
		floodfill(r[i], c[i]);
		for (int j=0; j<N+2; j++) {
			for (int k=0; k<N+2; k++) {
				visited[j][k] = false;
			}
		}
	}
	int answer = K*(K-1) - pairs;
	cout << answer/2;
}




