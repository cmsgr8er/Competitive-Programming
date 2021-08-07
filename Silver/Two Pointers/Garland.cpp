#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q; cin >> n;
	vector<char> word(n);
	set<char> colors;
	map<char, vector<int>> answer;
	map<char, bool> exists;
	for (int i=0; i<n; i++) {
		cin >> word[i];
		colors.insert(word[i]);
		exists[word[i]] = true;
	}
	for (char c: colors) {
		int free = 1;
		answer[c].resize(n+1);
		vector<int> position, difference;
		for (int i=0; i<n; i++) {
			if (word[i]==c) position.push_back(i);
		}
		if (position.size()==1) {
			for (int value = 1; value <=n; value++) answer[c][value] = value + 1;
		}
		else {
			for (int i=1; i<position.size(); i++) {
				difference.push_back(position[i]-position[i-1]-1);
			}
			for (int value =1; value <= n; value++) {
				int left = 0, right = 0, sum = 0;
				for (right = 0; right < position.size()-1; right++) {
					sum += difference[right];
					while (sum > value && left < right) {
						sum -= difference[left];
						left++;
					}
					if (sum <= value) free = max(free, right-left+2);
				}
				answer[c][value] = value + free;
			}
		}
		position.clear(); difference.clear();
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		int quantity; char color;
		cin >> quantity >> color;
		if (!exists[color]) {
			cout << quantity << endl;
		}
		else {
			cout << min(answer[color][quantity], n) << endl;
		}
	}
}
