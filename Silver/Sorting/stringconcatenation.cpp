#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    if (a==b) return false;
    else return a+b < b+a;
}

int main() {
	int n; cin >> n;
	vector<string> list(n);
	for (int i=0; i<n; i++) {
		cin >> list[i];
	}
	sort(list.begin(), list.end(), cmp);
	for (int i=0; i<n; i++) {
		cout << list[i];
	}
}
