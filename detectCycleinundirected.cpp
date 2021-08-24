#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)


//     UNDIRECTED GRAPH

using namespace std;

const int N = 1e5 + 1;
bool vis[N];

bool isCyclic(vvi ad, int node, int par = 1) {

    vis[node] = true;

    for(auto &it: ad[node]) {
        if(it != par) {
            if(vis[it]) {
                return true;
            }
            if(isCyclic(ad, it, node)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
	int n,m;
	cin>>n>>m;
	n++;
	vvi adj(n);
	rep(i,0,m) {
		int x, y;
		cin>> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

    bool flag = false;

    rep(i,1,n) {
        if(isCyclic(adj, i)) {
            flag = true;
            break;
        }
    }

    if(flag) {
        cout << "Cycle is present" <<endl;
    }else {
        cout << "Cycle is not present" <<endl;
    }
	return 0;

}
