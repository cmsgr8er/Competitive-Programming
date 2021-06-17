// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 10;
vector<int> starting, ending;
int N, counter =0;
vector<int> adj[MN];

void removeBridges() {
    for (int i=1; i<N+1; i++) {
        if (adj[i].size() == 1) {
            counter++;
            adj[adj[i][0]].erase(find(adj[adj[i][0]].begin(), adj[adj[i][0]].end(), i));
            adj[i].erase(adj[i].begin());
            starting.push_back(adj[i][0]);
            ending.push_back(i);
        }
    }
    if (counter != N-1) removeBridges();
}

int main() {
    int a,b;
    cin >> N;
    for (int i=1; i<= N-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    removeBridges();
    for (int i=0; i<N-1; i++) {
        cout << starting[i] << " " << ending[i] << "\n";
    }
    for (int i=N-2; i>=0; i--) {
        cout << ending[i] << " " << starting[i] << "\n";
    }
}
