#include <bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)

using namespace std;

const int INF = 1e7;

int main()
{
    int n, m;
    cin >> n >> m;

    n++;
    vvi adj(n, vi(n, INF));
    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    vvi dis = adj;

    rep(k, 1, n)
    {
        rep(i, 1, n)
        {
            rep(j, 1, n)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            if (dis[i][j] > 1e5)
                cout << "INF ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}