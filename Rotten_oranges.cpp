// Author : Sarthak Sharma
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
#define N 1e5
#define mod 1000000007
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

// <------------------------------------- Code ------------------------------------->
int n, m;
vvi grid;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
queue<pii> q;
int fcnt = 0;

bool isValid(int x, int y) {
    return (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 1);
}

int BFS() {
    int ans = 0;
    while(!q.empty()) {
        int ql = q.size();
        while(ql--) {
            int x = q.front().ff;
            int y = q.front().ss;
            q.pop();
            rep(i, 0, 4) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(isValid(nx, ny)) {
                    grid[nx][ny] = 2;
                    fcnt--;
                    q.push({nx, ny});
                }
            }
        }
        if(!q.empty()) ans++;
    }
    if(fcnt) return -1;
    return ans;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    cin >> n >> m;
    grid = vvi(n, vi(m, m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if(grid[i][j] == 2) {
                q.push({i, j});
            }
            if(grid[i][j] == 1) {
                fcnt++;
            }
        }
    }    
    int ans = BFS();
    cout << ans << endl;
    return 0;
}