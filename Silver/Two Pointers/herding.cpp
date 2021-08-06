#include <bits/stdc++.h>
using namespace std;
void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
	setIO("herding");
	int n; cin >> n;
	vector<int> location(n);
	for (int i=0; i<n; i++) {
		cin >> location[i];
	}
	sort(location.begin(), location.end());
	int maximum = max(location[n-2] - location[0] - n+2, location[n-1] - location[1] - n+2);
	int left=0, right=0, together, minimum = 1e5+10;
	while (left <=right && right < n) {
		together = right-left+1;
		if (right < n-1 && location[right+1] -location[left] <= n-1) right++;
		else if (location[right] - location[left] < n) {
			if ((left == 0 || right == n-1) && location[right]-location[left] != n-1) {
				minimum = min(minimum, n-together+1);
			}
			else minimum = min(minimum, n-together);
			right++;
		}
		else {
			left++;
		}
	}
	cout << minimum << endl << maximum;
}
