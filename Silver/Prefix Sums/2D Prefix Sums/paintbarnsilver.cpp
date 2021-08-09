#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
	int N, K, answer = 0; cin >> N >> K;
	int board[1002][1002], sum[1002][1002];
	for (int i=0; i<N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		board[x1+1][y1+1]++, board[x2+1][y2+1]++;
		board[x1+1][y2+1]--, board[x2+1][y1+1]--;
	}
	for (int i=1; i<1002; i++) {
		for (int j=1; j< 1002; j++) {
			sum[i][j] = board[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
    for (int i=1; i<1002; i++) {
        for (int j=1; j<1002; j++) {
            if (sum[i][j]==K) {
                answer++;
            }
        }
    }
    cout << answer;
}



