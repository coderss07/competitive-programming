#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)


//     DIRECTED GRAPH

using namespace std;

bool isCyclic(vvi ad, vb vis, vb st, int node = 1) {

    vis[node] = true;
    st[node] = true;

    for(auto &it: ad[node]) {
        if(vis[it] && st[it]) {
            return true;
        }

        if(isCyclic(ad, vis, st, it)) {
            return true;
        }

    }
    st[node] = false;
    return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	n++;
	vvi adj(n);
	rep(i, 0, m) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
	}

    vb vis(n, false);
    vb st(n, false);

    bool flag = false;

    rep(i, 1, n) {
        if(isCyclic(adj, vis, st, i)) {
            flag = true;
            break;
        }
    }

    if(flag) {
        cout << "Cycle is present" << endl;
    }else {
        cout << "Cycle is not present" << endl;
    }
	return 0;

}
