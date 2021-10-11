// Author : Sarthak Sharma
// date: 2021-10-08 21:10:14
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
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

const int N = 1e5 + 10;
vector<int> adj[N];
int col[N], ans = 1;

void DFS(int node, int par){
    for(auto it : adj[node]){
        if(it != par) {
            if(col[it] != col[node])
                ans++;
            DFS(it, node);
        }
    }
}

int main() {
	clock_t begin_69 = clock();
    fast_io;
    int n, i, p;
    cin >> n;
    rep(i, 1, n) {
        cin >> p;
        p--;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
	rep(i, 0, n) cin >> col[i];
	DFS(0, -1);
	cout << ans << endl;
}