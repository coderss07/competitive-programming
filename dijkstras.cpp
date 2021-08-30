#include<bits/stdc++.h>
#define vvpi vector< vector< pair< int, int > > >
#define vi vector<int>
#define pii pair<int,int>
#define rep(i,a,b) for (int i = a; i < b; i++)

using namespace std;

vvpi adj;
vi dis;
vector<int> par;

int32_t main() {
    int n, m; cin >> n >> m;
    adj = vvpi(n + 1);
    dis = vi(n + 1, INT_MAX);
    par = vector<int>(n + 1);
    rep(i,0,m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int sc;
    cin >> sc;

    dis[1] = 0;
    multiset<pii> s;
    // w v in set
    s.insert({0, sc});

    while(!s.empty()) {

        auto p = *(s.begin());
        s.erase(p);

        for(auto &it: adj[p.second]) {
            if(dis[it.first] > dis[p.second] + it.second) { // if u -> v then, dis[v] > dis[u] + wt[u->v]

                s.erase({dis[it.first], it.first});
                dis[it.first] = dis[p.second] + it.second;
                s.insert({dis[it.first], it.first});
            }
        }

    }
    rep(i, 1, n + 1) {
        cout << dis[i] << " ";
    }cout << endl;y

    return 0;
}