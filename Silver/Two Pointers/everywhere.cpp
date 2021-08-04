#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, left = 0, right = 0; cin >> n;
	char type[n];
	map<char, int> quantity;
	set<char> pokemon, total;
	for (int i=0; i<n; i++) {
		cin >> type[i];
		total.insert(type[i]);
	}
	int goal = total.size(), answer = 1e5+10;
	pokemon.insert(type[0]);
	quantity[type[0]] = 1;
	while (left <= right && right < n) {
		if (pokemon.size() < goal) {
			right++;
			if (quantity[type[right]] == 0) {
				pokemon.insert(type[right]);
			}
			quantity[type[right]]++;
		}
		else {
			answer = min(answer, right-left+1);
			if (quantity[type[left]] == 1) {
				pokemon.erase(pokemon.find(type[left]));
			}
			quantity[type[left]]--;
			left++;
		}
	}
	cout << answer;
}
