#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; ++i)


//     UNDIRECTED GRAPH

using namespace std;

int get_com(vvi adj, vector<bool> &vis, int node) {
    if(vis[node]) {
        return 0;
    }
    vis[node] = true;
    int ans = 1;
    for(auto &it: adj[node]) {
        ans += get_com(adj, vis, it);
    }
    return ans;
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

    vector<bool> vis(n,0);
    vi con_com;

    rep(i,1,n) {
        if(!vis[i]) {
            con_com.push_back(get_com(adj, vis, i));
        }
    }


    rep(i,0,con_com.size()) {
        cout<< i+1 << ": " << con_com[i] << endl;
    }
	return 0;

}
