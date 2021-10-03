// Author : Sarthak Sharma
#include<bits/stdc++.h>
//<------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
#define N 100000
#define mod 1000000007
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab " "
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vc vector<char>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

//<------------------------------------- Code ------------------------------------->
int n, m;
vvc grid;
vvi timing;
vvi dis;
vvi vis;
queue<pii> q;
pii sc;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool isValid_Mon(int x, int y) {
    return (x < n && x >= 0 && y < m && y >= 0 && !vis[x][y] && grid[x][y] != '#');
}

bool isValid_Man(int x, int y) {
    return (x < n && x >= 0 && y < m && y >= 0 && !vis[x][y] && grid[x][y] == '.');
}

void BFS() {
    // Multi Source BFS
    while(!q.empty()) {
        int qn = q.size();
        while(qn--) {
            int x = q.front().ff;
            int y = q.front().ss;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(isValid_Mon(newx, newy)) {
                    vis[newx][newy] = 1;
                    timing[newx][newy] = timing[x][y] + 1;
                    q.push({newx, newy});
                }
            }
        }
    }
    
    // Single Source BFS
    q.push(sc);
    vis = vvi(n, vi(m, 0));
    vis[sc.ff][sc.ss] = 1;
    while(!q.empty()) {
        int qn = q.size();
        while(qn--) {
            int x = q.front().ff;
            int y = q.front().ss;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(isValid_Man(newx, newy)) {
                    vis[newx][newy] = 1;
                    dis[newx][newy] = dis[x][y] + 1;
                    q.push({newx, newy});
                }
            }
        }
    }
    // rep(i, 0, n) {
    //     rep(j, 0 ,m) {
    //         if(dis[i][j] != N)
    //         cerr << dis[i][j] << " ";
    //     else cerr << "P ";
    //     }cerr << endl;
    // }
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    cin >> n >> m;
    grid = vvc(n, vc(m));
    timing = vvi(n, vi(m, N));
    dis = vvi(n, vi(m, N));
    vis = vvi(n, vi(m, 0));

    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if(grid[i][j] == 'P') {
                q.push({i, j});
                vis[i][j] = 1;
                timing[i][j] = 0;              
            }else if(grid[i][j] == 'T') {
                sc = {i, j};
                dis[i][j] = 0;
            }
            
        }
    }
    
    BFS();
    bool flag = false;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if(dis[i][j] < timing[i][j]) {
                    flag = true;
                }
            }
        }
    }
    if(flag) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }


    return 0;
}