#include <bits/stdc++.h>
using namespace std;
bool visited[22][22];
char grid[22][22];
int N, r1, r2, c1, c2, counterA = 0, counterB = 0;
set<char> s;
vector<pair<pair<int, int>, pair<int, int>>> pcl;
map<char, int> num;
void floodfill(int r, int c) {
	if (r<r1 || r>r2 || c<c1 || c>c2) return;
	visited[r][c] = true;
	if (grid[r][c] == grid[r1][c1]) counterA++;
	else counterB++;
	int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
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
	setIO("where");
	set<int> subsets;
	pair<int, int> b;
	cin >> N;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cin >> grid[i][j];
		}
	}
	for (int x1=1; x1<= N; x1++) {
		for (int x2 = x1; x2<=N; x2++) {
			for (int y1=1; y1<=N; y1++) {
				for (int y2=y1; y2<=N; y2++) {
					r1=x1, r2=x2, c1=y1, c2=y2;
					counterA =0, counterB =0, s.clear(), num.clear();
					for (int i=x1; i<= x2; i++) {
						for (int j=y1; j<=y2; j++) {
							num[grid[i][j]]++;
							s.insert(grid[i][j]);
							if (grid[i][j] != grid[r1][c1]) b = {i,j};
						}
					}
					if (s.size() == 2) {
						floodfill(r1,c1);
						floodfill(get<0>(b), get<1>(b));
						if (counterA == num[grid[r1][c1]] && counterB < num[grid[get<0>(b)][get<1>(b)]]){
							pcl.push_back({{r1,c1}, {r2, c2}});
						}
						if (counterA < num[grid[r1][c1]] && counterB == num[grid[get<0>(b)][get<1>(b)]]){
							pcl.push_back({{r1,c1}, {r2, c2}});
						}
					}
					for (int i=x1-1; i<= x2+1; i++) {
						for (int j=y1-1; j<=y2+1; j++) {
							visited[i][j] = false;
						}
					}
				}
			}
		}
	}
	if (pcl.size() > 0) {
		for (int i=0; i<pcl.size(); i++) {
			for (int j=0; j<pcl.size(); j++) {
				if (j != i) {
					if (get<0>(get<0>(pcl[i])) <= get<0>(get<0>(pcl[j]))
						&& get<1>(get<0>(pcl[i])) <= get<1>(get<0>(pcl[j]))
						&& get<0>(get<1>(pcl[i])) >= get<0>(get<1>(pcl[j]))
						&& get<1>(get<1>(pcl[i])) >= get<1>(get<1>(pcl[j]))) {
						subsets.insert(j);
					}
				}
			}
		}
		cout << pcl.size()-subsets.size();
	}
	else cout << 0;
}


