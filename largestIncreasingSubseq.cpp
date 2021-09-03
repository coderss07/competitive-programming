#include<bits/stdc++.h>
#define vi vector<int>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

vi dp;

int largestIncSubseq(vi &a, int n) {
    if(dp[n] != -1) return dp[n];

    dp[n] = 1;
    rep(i, 0, n) {
        if(a[n] > a[i]) {
            dp[n] = max(dp[n], 1 + largestIncSubseq(a, i));
        }
    }

    return dp[n];
}

int32_t main() {
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    // dp = vi(n, -1);
    // cout << largestIncSubseq(a, n - 1) << endl;

    dp = vi(n, 1);
    rep(i, 1, n) {
        rep(j, 0, i) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    cout << dp[n -1] << endl;

    return 0;
}