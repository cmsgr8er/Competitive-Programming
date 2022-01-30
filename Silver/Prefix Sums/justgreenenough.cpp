#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 501;
int G[MN][MN], n;

ll without(int beauty) {
	int column[n][n+1], bad[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			bad[i][j] = (G[i][j] <= beauty);
		}
	}
	for (int i=0; i<n; i++) {
		column[i][0] = 0;
		for (int j=0; j<n; j++) column[i][j+1] = column[i][j] + bad[i][j];
	}
	long long grids=0;
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			int height=0;
			for (int h=0; h<n; h++) {
				if (column[h][j+1] > column[h][i]) {
					grids += height*(height+1)/2;
					height = 0;
				}
				else height++;
			}
			grids += height*(height+1)/2;
		}
	}
	return grids;
}

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> G[i][j];
		}
	}
	cout << without(99) - without(100);
}