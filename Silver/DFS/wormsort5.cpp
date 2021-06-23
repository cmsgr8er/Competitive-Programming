// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 10;
int N, M, counter;
bool visited[MN];
vector<pair<int, int>> adj[MN];
vector<int> misordered;

void dfs(int node, int minwidth) {
    visited[node] = true;
    for (auto u: adj[node]) {
        if (!visited[get<0>(u)] && get<1>(u) >= minwidth) {
            dfs(get<0>(u), minwidth);
        }        
    }
}

bool isConnected(int wide) {
    bool connected = false;
    counter = 0;
    dfs(misordered[0], wide);
    for (int i=0; i<misordered.size(); i++) {
        if (visited[misordered[i]]) counter++;
    }
    if (counter == misordered.size()) {
        connected = true;
    }
    memset(visited, 0, N+2);
    return connected;
}

void setIO(string fileName = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if((int)fileName.size()) {
        freopen((fileName+".in").c_str(), "r", stdin);
        freopen((fileName+".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("wormsort");
    cin >> N >> M;
    int permutation[N+1], a, b, c, minimum, check = 0, left = 0, right = M-1, middle;
    int widths[M];
    permutation[0] = 0;
    for (int i=1; i<= N; i++) {
        cin >> permutation[i];
        if (permutation[i] != i) {
            misordered.push_back(i);
        }
        else {
            check++;
        }
    }
    if (check == N) {
        minimum = -1;
    }
    else {
        for (int i=1; i<= M; i++) {
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
            widths[i-1] = c;
        }
        sort(widths, widths + M);
        while (left < right) {
            middle = (left + right+1)/2;
            if (isConnected(widths[middle])) {
                left = middle;
            }
            else {
                right = middle-1;
            }
        }
        minimum = widths[left];
        
    }
    cout << minimum;
}
