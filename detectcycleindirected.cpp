#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)


//     DIRECTED GRAPH

using namespace std;

bool isCyclic(vvi ad, vb st, int node = 1) {

    st[node] = true;

    for(auto &it: ad[node]) {
        if(st[it] or isCyclic(ad, st, it)) {
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

    vb st(n, false);

    bool flag = false;

    rep(i, 1, n) {
        if(isCyclic(adj, st, i)) {
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
