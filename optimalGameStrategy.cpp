#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define vvi vector< vi >
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

const int N = 1e3;
vvi dp;

ll solve(vi& a, int i, int j) {

    if(i == j) return a[i];

    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    ll l = a[i] + min(solve(a, i + 2, j), solve(a, i + 1, j - 1));

    ll r = a[j] + min(solve(a, i + 1, j - 1), solve(a, i, j - 2));

    return dp[i][j] = max(l, r);

}

int main() {
    
    int n; cin >> n;
    n++;
    vi a(n);
    rep(i, 1, n) cin >> a[i];
    dp = vvi(n, vi(n, -1));
    cout << solve(a, 1, n - 1) << endl;

    return 0;
}