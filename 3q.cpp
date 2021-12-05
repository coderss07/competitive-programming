// Author : Sarthak Sharma
// Date: 2021-10-16 17:02

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int, int>
#define ff first
#define N 1e5
#define mod 1000000007
#define ss second
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab1 " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)
#define fbo find_by_order
#define oof order_of_key

using namespace std;
using namespace __gnu_pbds;

// <------------------------------------- Templates ------------------------------------->
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

// <------------------------------------- Code ------------------------------------->
vvi adj;
int sc, ds;
int n;

int DFS(int node, int k, int wt) {
    if(k < 0) {
        return N;
    }
    if(k == 0) {
        if(node == ds) {
            return wt;
        }
        return N;
    }
    int ans = N;
    rep(i, 1, n) {
        int tmp = DFS(i, k - 1, wt + adj[node][i]);
        if(adj[node][i] and tmp != N) {
            ans = min(ans, tmp);
        }
    }
    return ans;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    cin >> n;
    n++;
    adj = vvi(n, vi(n));
    int edge = 0;
    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> adj[i][j];
        }
    }
    cin >> sc >> ds;
    int k; cin >> k;

    int ans = DFS(sc, k, 0);
    if(ans != N) {
        cout << "Weight of shortest path from (" << sc << ", " << ds << ") with " << k << " edges : " << ans << endl;
    }else {
        cout << "no path of length " << k << " is available." << endl;
    }
    
        
    #ifndef ONLINE_JUDGE
          clock_t terminator_69 = clock();
          cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif 
    return 0;
}
