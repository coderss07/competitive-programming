#include<bits/stdc++.h>
#define vvi vector< vector< int > >
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int count_cell(vvi &adj, int i, int j) {
    if(i < 0 || j < 0 || i >= adj.size() || j >= adj[0].size()) return 0;

    if(adj[i][j] == 0) return 0;

    int cnt = adj[i][j];
    adj[i][j] = 0;

    cnt += count_cell(adj, i - 1, j);
    cnt += count_cell(adj, i, j - 1);
    cnt += count_cell(adj, i + 1, j);
    cnt += count_cell(adj, i, j + 1);
    cnt += count_cell(adj, i - 1, j - 1);
    cnt += count_cell(adj, i - 1, j + 1);
    cnt += count_cell(adj, i + 1, j - 1);
    cnt += count_cell(adj, i + 1, j + 1);

    return cnt;
}

int maxRegion(vvi &adj) {
    int ans = 0;
    rep(i, 0, adj.size()) {
        rep(j, 0, adj[0].size()) {
            ans = max(ans, count_cell(adj, i, j));
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vvi adj(n, vi(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> adj[i][j];
        }
    }
    cout << maxRegion(adj) << endl;
    return 0;
}