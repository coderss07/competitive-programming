#include<bits/stdc++.h>
#define vi vector<int>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

vi dp;
unordered_map<int, int> mp;

int largestIncSubseq(vi &a, int n) {
    if(dp[n] != -1) return dp[n];

    dp[n] = 1;
    rep(i, 0, n) {
        if(a[n] > a[i]) {
            dp[n] = max(dp[n], 1 + largestIncSubseq(a, i));
        }else
            dp[n] = max(dp[n], largestIncSubseq(a, i));
        mp[dp[n]]++;
    }

    return dp[n];
}

int32_t main() {
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    dp = vi(n, -1);
    int ans = largestIncSubseq(a, n - 1);

    // dp = vi(n, 1);
    // rep(i, 1, n) {
    //     rep(j, 0, i) {
    //         if(a[i] > a[j]) {
    //             dp[i] = max(dp[i], 1 + dp[j]);
    //         }
    //     }
    // }
    // int ans = 1;
    // rep(i, 0, n) {
    //     cerr << dp[i] << " ";
    //     ans = max(ans, dp[i]);
    // }
    cout << ans << endl;
    for(auto &it: mp) cout << it.first << " " << it.second << endl;

    return 0;
}