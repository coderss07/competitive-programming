#include<bits/stdc++.h>
#define vvi vector< vector< int > >
#define vi vector<int>
#define rep(i,a,b) for (int i = a; i < b; i++)

using namespace std;

const int INF = 1e7;
vvi adj;
vi dis;

int32_t main() {
    int n,m; cin >> n >> m;
    dis = vi(n + 1, INF);
    rep(i,0,m) {
        int u,v,w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
    int sc;
    cin>>sc;

    dis[sc] = 0;

    int i = n-1;
    while(i--) {
        for(auto &it: adj) {
            dis[it[1]] = min( dis[it[1]], dis[it[0]] + it[2]);
        }
    }

    rep(i,1,n+1) {
        cout<< dis[i] << " ";
    }cout<< endl;

    return 0;
}