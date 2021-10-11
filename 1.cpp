// Author : Sarthak Sharma
// date: 2021-10-09 21:10:14
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
#define tab1 " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

// <------------------------------------- Code ------------------------------------->


void solve() {
    int n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vvi cnt(n + 1, vi(1, 0));
    rep(i, 0, n) {
        cnt[a[i]][0]++;
        cnt[a[i]].pb(i);
    }
    for(auto ae: cnt) {
        for(auto it: ae) {
            cout << it << tab1;
        }cout << endl;
    }
    vi b;
    int last = n + 1;
    rep(it, 0, cnt.size()) {
        if(cnt[it][0] == 0) {
            last = it;
            b.pb((n * (n + 1)) / 2);
            break;
        }
        int ans = 0;
        int tmp = -1;
        rep(i, 1, cnt[it][0] + 1) {
            int j = (cnt[it][i] - tmp - 1);
            ans += ((j * (j + 1)) / 2);
            tmp = cnt[it][i];
        }
        int j = n - tmp - 1;
        ans += ((j * (j + 1)) / 2);
        b.pb(ans);
    }
    rep(i, 1, last + 1) {
        rep(j, 0, )
        cnt[a[i]][0]++;
        cnt[a[i]].pb(i);
    }

    for(auto &it: b) {
        cerr << it << tab1;
    }cerr << endl;
    // cout << ans[k - 1] << endl;
}


int main() {
	clock_t begin_69 = clock();
    fast_io;
    int t; cin >> t;
    while(t--) {
        solve();
    }
}