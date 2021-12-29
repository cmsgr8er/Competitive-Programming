#include <bits/stdc++.h>
using namespace std;

int main() {
	string recipe; cin >> recipe;
	int b=0,s=0,c=0;
	for (int i=0; i<recipe.length(); i++) {
		if (recipe[i] == 'B') b++;
		else if (recipe[i]=='S') s++;
		else c++;
	}
	int nb,ns,nc; cin >> nb >> ns >> nc;
	int pb,ps,pc; cin >> pb >> ps >> pc;
	long long r; cin >> r;
	long long lo=0, hi=1e13, burgers;
	while (lo < hi) {
		burgers = (lo+hi+1)/2;
		long long cost = (max(burgers*b-nb,(long long) 0))*pb + (max(burgers*s-ns, (long long) 0))*ps + (max(burgers*c-nc, (long long) 0))*pc;
		if (cost <= r) lo=burgers;
		else hi = burgers-1;
	}
	cout << lo;
} 