#include<bits/stdc++.h>
#define vvpi vector< vector< pair< int, int > > >
#define vb vector<bool>
#define vi vector<int>
#define pii pair<int,int>
#define rep(i,a,b) for (int i = a; i < b; i++)

using namespace std;
/*
7 11
1 3 7
1 4 5
2 3 8
2 4 5
3 4 9
3 5 7
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
1*/
const int INF = 1e5;

vvpi adj;
vb vis;
vi dis;
vector<int> par;

int32_t main() {
    int n, m; cin >> n >> m;
    adj = vvpi(n + 1);
    vis = vb(n + 1, false);
    par = vector<int>(n + 1);
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

    }
    int sc; cin >> sc;

    dis = vi(n + 1, INF);
    dis[sc] = 0;

    int edge = n - 1;
    vis[sc] = true;
    int cost = 0;
    multiset<pii> s;
    for(auto &it: adj[sc]) {
        if(!vis[it.first] && dis[it.first] > it.second) {
            dis[it.first] = it.second;
            s.insert({it.second, it.first});
            par[it.first] = sc;
        }
    }

    int r = 1;
    while(edge--) {

        auto p = *(s.begin());
        s.erase(p);
        vis[p.second] = true;

        cost += p.first;
            
        cout << par[p.second] << " " << p.second <<endl;

        for(auto &it: adj[p.second]) {
            if(!vis[it.first] && dis[it.first] > it.second) {
                s.erase({dis[it.first], it.first});
                dis[it.first] = it.second;
                s.insert({it.second, it.first});
                par[it.first] = p.second;
            }
        }

    }
    cout << cost << endl;

    return 0;
}