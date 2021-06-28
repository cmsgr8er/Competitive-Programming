#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, K, a,b, median;
	cin >> N >> K;
	int difference[N+1], stack[N];
	for (int i=0; i<N+1; i++) {
		difference[i] = 0;
	}
	for (int i=0; i<K; i++) {
		cin >> a >> b;
		difference[a]++;
		if (b!= N) difference[b+1]--;
	}
	stack[0] = difference[1];
	for (int i=0; i<N-1; i++) {
		stack[i+1] = stack[i] + difference[i+2];
	}
	sort(stack, stack + N);
	cout << stack[(N-1)/2];
}
