#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main() {
	int k, m, n; cin >> k >> m >> n;
	vector<pair<int, int>> patches(k);
	for (int i=0; i<k; i++) cin >> patches[i].first >> patches[i].second;
	sort(patches.begin(), patches.end());
	vector<int> p(k), t(k); 
	for (int i=0; i<k; i++) {
		p[i] = patches[i].first;
		t[i] = patches[i].second;
	}
	vector<int> bad(m); for (int i=0; i<m; i++) cin >> bad[i];
	sort(bad.begin(), bad.end());
	
	vector<long long> gaps(m+1), gapsum(m+1), gapmax(m+1);
	// find gaps that are 1 and 2:
	gaps[0] = 1; gaps[m] = 1;
	for (int i=1; i<m; i++) {
		int lo = lower_bound(p.begin(), p.end(), bad[i-1]) - p.begin();
		if (p[lo] < bad[i]) {
			int hi = lower_bound(p.begin(), p.end(), bad[i]) - p.begin() - 1;
			long long sum = 2*(bad[i]-p[hi] + p[lo]-bad[i-1]);
			if (sum > bad[i] - bad[i-1]) gaps[i] = 1;
			else gaps[i] = 2;
		}
		else gaps[i] = 1;
	}
	// find gapsum
	int end = k-1; gapsum[m] = 0;
	while (p[end] > bad[m-1]) {
		gapsum[m] += t[end];
		end--;
	}
	int index = 0;
	for (int i=0; i<m; i++) {
		gapsum[i] = 0;
		while (index < k && p[index] < bad[i]) {
			gapsum[i] += t[index];
			index++;
		}
	}
	// find gapmax:
	for (int i=0; i<=m; i++) {
		if (gaps[i] == 1) gapmax[i] = gapsum[i];
		else {
			gapmax[i] = 0;
			int l = lower_bound(p.begin(), p.end(), bad[i-1])-p.begin();
			int h = lower_bound(p.begin(), p.end(), bad[i])-p.begin()-1;
			vector<pair<int, int>> checkpoints;
			for (int j=l; j<=h; j++) {
				if (2*p[j]-bad[i-1] <= bad[i]){
					checkpoints.push_back({2*p[j]-bad[i-1], -t[j]});
					checkpoints.push_back({bad[i-1], t[j]});
				}
				if (2*p[j]-bad[i] >= bad[i-1]){
					checkpoints.push_back({2*p[j]-bad[i], t[j]});
				}				
			}
			sort(checkpoints.begin(), checkpoints.end());
			ll sum = 0;
			for (int k=0; k<checkpoints.size(); k++) {
				sum += checkpoints[k].second;
				gapmax[i] = max(gapmax[i],sum);
			}
			checkpoints.clear();
		}
	}
	// extract answer:
	ll answer = 0;
	for (int i=0; i<=m; i++) {
		if (gaps[i] == 2) gapmax.push_back(gapsum[i] - gapmax[i]);
	}
	sort(gapmax.rbegin(), gapmax.rend());
	int num = 0;
	while (num < n && gapmax[num] > 0) {
		answer += gapmax[num];
		num++;
	}
	cout << answer;
} 