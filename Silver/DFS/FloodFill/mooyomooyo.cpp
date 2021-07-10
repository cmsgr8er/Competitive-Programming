#include <bits/stdc++.h>
using namespace std;
bool visited[102][12];
int grid[102][12], N, connected = 0;
vector<pair<int, int>> region;
void gravity(int c) {
	vector<int> colors;
	for (int i=1; i<=N; i++) {
		if (grid[i][c] != 0) colors.push_back(grid[i][c]);
		grid[i][c] = 0;
	}
	for (int i=0; i<colors.size(); i++) {
		grid[N-colors.size()+1+i][c] = colors[i];
	}
}
void floodfill(int r, int c) {
	visited[r][c] = true;
	if (r==0 || r == N+1 || c==0 || c==11) return;
	connected++;
	region.push_back({r,c});
	int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
	for (int i=0; i<4; i++) {
		if (!visited[r+dx[i]][c+dy[i]] && grid[r+dx[i]][c+dy[i]] == grid[r][c]) {
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
	setIO("mooyomooyo");
	int K, state = 1;
	char digit;
	cin >> N >> K;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=10; j++) {
			cin >> digit;
			grid[i][j] = digit -'0';
		}
	}
	while (state !=0) {
		state = 0;
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=10; j++) {
				if (grid[i][j] != 0 && !visited[i][j]) {
					connected = 0;
					floodfill(i,j);
					if (connected >= K) {
						state++;
						for (int k=0; k<region.size(); k++) {
							grid[get<0>(region[k])][get<1>(region[k])] = 0;
						}
					}
					region.clear();
				}
			}
		}
		for (int i=1; i<=10; i++) gravity(i);
		for (int i=0; i<N+2; i++) {
			for (int j=0; j<12; j++) {
				visited[i][j] = false;
			}
		}
	}
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=10; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}



