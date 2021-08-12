#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll n,t; cin >> n >> t;
    ll k[n]; 
    for (int i=0; i<n; i++) {
        cin >> k[i];
    }
    ll left = 1, right = 1e18;
    while (left < right) {
        ll middle = (left + right)/2, products = 0;
        for (int i=0; i<n; i++) {
            products += middle/(k[i]);
            if (products >= t) break;
        }
        if (products >= t) right = middle;
        else left = middle+1;
    }
    cout << left;
}
