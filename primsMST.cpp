#include<bits/stdc++.h>
#define vvpi vector< vector< pair< int, int > > >
#define vb vector<bool>
#define pii pair<int,int>
#define rep(i,a,b) for (int i = a; i < b; i++)

using namespace std;

vvpi adj;
vb vis;
vector<int> par;

int32_t main() {
    int n,m; cin >> n >> m;
    adj = vvpi(n + 1);
    vis = vb(n + 1,false);
    par = vector<int>(n + 1);
    rep(i,0,m) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

    }

    int edge = n - 1;
    vis[1] = true;
    int cost = 0;
    multiset<pii> s;
    for(auto &it: adj[1]) {
        if(!vis[it.second]) {
            s.insert({it.second, it.first});
            par[it.first] = 1;
        }
    }
    int r = 1;    
    while(edge--) {

        auto p = *(s.begin());
        s.erase(p);
        vis[p.second] = true;

        cost += p.first;
            
        cout << par[p.second] << " " << (p.second) <<endl;

        for(auto &it: adj[p.second]) {
            if(!vis[it.first]) {
                s.insert({it.second, it.first});
                par[it.first] = p.second;
            }
        }

    }
    cout << cost << endl;

    return 0;
}