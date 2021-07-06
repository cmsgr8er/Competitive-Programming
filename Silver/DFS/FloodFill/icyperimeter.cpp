#include <bits/stdc++.h>
using namespace std;
bool grid[1002][1002];
char table[1002][1002];
int N, a = 0, per = 0, area, perimeter = 3e6+ 10;
void floodfill(int x, int y) {
	grid[x][y] = true;
	if (x > N || y > N) return;
	if (x == 0 || y == 0) return;
	if (table[x][y] == '.') return;
	a++;
	if (table[x][y+1] != '#') per++;
	if (table[x][y-1] != '#') per++;
	if (table[x+1][y] != '#') per++;
	if (table[x-1][y] != '#') per++;
	if (!grid[x-1][y]) floodfill(x-1, y);
	if (!grid[x][y-1]) floodfill(x,y-1);
	if (!grid[x+1][y]) floodfill(x+1,y);
	if (!grid[x][y+1]) floodfill(x,y+1);
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("perimeter");
	cin >> N;
	vector<pair<int, int>> p;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cin >> table[i][j];
		}
	}
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			if (table[i][j] == '#' && !grid[i][j]) {
				a = 0, per=0;
				floodfill(i,j);
				p.push_back({a, per});
			}
		}
	}
	sort(p.begin(), p.end());
	area = get<0>(p[p.size()-1]);
	for (int i=0; i<p.size(); i++) {
		if (get<0>(p[i]) == area) perimeter = min(perimeter, get<1>(p[i]));
	}
	cout << area << " " << perimeter;
}




