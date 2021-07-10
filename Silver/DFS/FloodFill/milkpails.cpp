#include <bits/stdc++.h>
using namespace std;
int X, Y, M, K, answer = 205;
bool visited[300][300][300];
void floodfill(int r, int c, int depth) {
	visited[r][c][depth] = true;
	if (r<0 || r>X || c<0 || c>Y || depth > K) return;
	answer = min(answer, abs(M-r-c));
	if (r+c-X >=0 && !visited[X][r+c-X][depth+1]) floodfill(X, r+c-X, depth+1);
	if (r+c-Y >=0 && !visited[r+c-Y][Y][depth+1]) floodfill(r+c-Y, Y, depth+1);
	if (r+c<=Y && !visited[0][r+c][depth+1]) floodfill(0, r+c, depth+1);
	if (r+c<=X && !visited[r+c][0][depth+1]) floodfill(r+c,0, depth+1);
	if (!visited[r][Y][depth+1]) floodfill(r,Y, depth+1);
	if (!visited[X][c][depth+1]) floodfill(X,c, depth+1);
	if (!visited[r][0][depth+1]) floodfill(r,0, depth+1);
	if (!visited[0][c][depth+1]) floodfill(0,c, depth+1);
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("pails");
	cin >> X >> Y >> K >> M;
	floodfill(0,0,0);
	cout << answer;
}




