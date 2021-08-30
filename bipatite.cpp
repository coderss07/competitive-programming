#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)


//     UNDIRECTED GRAPH

using namespace std;

bool isBipartite(vvi &ad, int node, vi col, int c = 0) {

    if(col[node] != -1 && col[node] != c) {
        return false;
    }
    if(col[node] == c){
        return true;
    }
    col[node] = c;

    for(auto &it: ad[node]) {
        if(!isBipartite(ad, it, col, (c xor 1))) {
            return false;
        }
    }
    return true;
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
		adj[y].push_back(x);
	}

    bool flag = true;
    vector<int> col(n, -1);

    rep(i, 1, n) {
        if(!isBipartite(adj, i, col)) {
            flag = false;
            break;
        }
    }

    if(flag) {
        cout << "Bipartite" << endl;
    }else {
        cout << "Not bipartite" << endl;
    }
	return 0;

}
