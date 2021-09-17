#include <bits/stdc++.h>
using namespace std;

bool visited[3002][3002];
int total = 0;

void placeCows(int r, int c) {
	int neighbors = 0, dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, xmiss, ymiss;
	if (visited[r][c]) {
		for (int i=0; i<4; i++) {
			if (visited[r+dx[i]][c+dy[i]]) neighbors++;
			else {
				xmiss = r+dx[i];
				ymiss = c+dy[i];
			}
		}
		if (neighbors == 3) {
			visited[xmiss][ymiss] = true;
			total++;
			placeCows(xmiss, ymiss);
			for (int i=0; i<4; i++) {
				placeCows(xmiss+dx[i], ymiss+dy[i]);
			}
		}
		else return;
	}
	else return;
}
int main() {
	int N, x, y; cin >> N;
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		if (!visited[1000+x][1000+y]) total++;
		visited[1000+x][1000+y] = true;
		placeCows(1000+x, 1000+y);
		int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
		for (int i=0; i<4; i++) placeCows(1000+x+dx[i], 1000+y+dy[i]);
		cout << total - (i+1) << endl;
	}
}





