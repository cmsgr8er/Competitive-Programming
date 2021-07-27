#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

vl psum(vl a) {
	vl p(a.size() + 1);
	for (int i=0; i<a.size(); i++) {
		p[i+1] = p[i]+a[i];
	}
	return p;
}
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("rental");
	int N, M, R;
	ll answer = 0;
	cin >> N >> M >> R;
	vl cows(N), rent(R), quantity(M), price(M);
	vector<pair<int, int>> gallons(M); // first coordinate is cents, second is num of gallons
	for (int i=0; i<N; i++) {
		cin >> cows[i];
	}
	for (int i=0; i<M; i++) {
		int p, q;
		cin >> p >> q;
		gallons[i].first = q; gallons[i].second = p;
	}
	for (int i=0; i<R; i++) {
		cin >> rent[i];
	}
	sort(cows.rbegin(), cows.rend());
	sort(rent.rbegin(), rent.rend());
	sort(gallons.rbegin(), gallons.rend());
	for (int i=0; i<M; i++) {
		price[i] = gallons[i].first;
		quantity[i] = gallons[i].second;
	}
	vl totalrent = psum(rent), totalGallons = psum(quantity), totalCows = psum(cows), psumGallons(M+1);
	for (int i=0; i<M; i++) {
		psumGallons[i+1] = psumGallons[i] + price[i]*quantity[i];
	}
	vl profit(N+1);
	for (int i=0; i<min(N+1,R+1); i++) { // i cows rented
		int index = lower_bound(totalGallons.begin(), totalGallons.end(), totalCows[N-i]) - totalGallons.begin() - 1;
		profit[i] = min(psumGallons[index] + (totalCows[N-i] - totalGallons[index])*price[index], psumGallons[M]) + totalrent[i];
	}
	for (int i=0; i< N+1; i++) {
		answer = max(answer, profit[i]);
	}
	cout << answer;
}
