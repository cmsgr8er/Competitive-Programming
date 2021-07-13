#include <bits/stdc++.h>
using namespace std;
bool visited[2010][2010];
set<pair<pair<int, int>, pair<int, int>>> edges;
int N, cardinality, regions = 0, directions[1001]; // 0 = N, 1 = E, 2 = S, 3 = W
void traverse(int r, int c, int i) {
	if (i == N) return;
	int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
	for (int j = 0; j < 4; j++) {
		if (directions[i] == j) {
			cardinality = edges.size();
			edges.insert({{r,c}, {r+dx[j], c+dy[j]}});
			edges.insert({{r+dx[j], c+dy[j]}, {r,c}});
			if (visited[r + dx[j]][c + dy[j]] && edges.size() != cardinality) regions++;
			visited[r][c] = true;
			traverse(r + dx[j], c + dy[j], i + 1);
		}
	}

}
void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if ((int) fileName.size()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
}
int main() {
	setIO("gates");
	char x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 'N')
			directions[i] = 0;
		if (x == 'E')
			directions[i] = 1;
		if (x == 'S')
			directions[i] = 2;
		if (x == 'W')
			directions[i] = 3;
	}
	traverse(1002, 1002, 0);
	cout << regions;
}





