// Author : Sarthak Sharma
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
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
// using namespace __gnu_pbds;

// <------------------------------------- Code ------------------------------------->

void solve() {
    ll n, m; cin >> n >> m;
    vvl a(n - 1, vl(3));
    vl st(3);
    cin >> st[0] >> st[1] >> st[2];
    rep(i, 0, n - 1) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(), a.end());
    for(auto it: a) {
        cerr << it[0] << " " << it[1] << " " << it[2] << endl;
    }
    while(m--) {
        ll k; cin >> k;
        vl tmp = st;
        if(k > tmp[2]) {
            k = tmp[2];
        }
        tmp[0] += k;
        tmp[2] -= k;
        auto it = (upper_bound(a.begin(), a.end(), tmp) - a.begin());
        cout << n - it << endl;
    }
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}