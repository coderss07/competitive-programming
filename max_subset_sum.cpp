#include<bits/stdc++.h>
#define vi vector<int>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

/* find the sum of the subset of non adjacent elements min sum = 0;
*/

vi dp;

int maxSumSubset(vi &a, int n, int i = 0) {

    if(dp[i] != -1) {
        return dp[i];
    }

    if(i == n - 1) {
        dp[i] = a[i];
    }else if(i == n - 2) {
        dp[i] = max(a[i], a[i + 1]);
    }else {
        dp[i] = max(a[i], max(a[i] + maxSumSubset(a, n, i + 2), maxSumSubset(a, n, i + 1)));
    }
    return dp[i];

}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n);
        dp = vi(n, -1);
        rep(i, 0, n) {
            cin >> a[i];
        }
         cout << maxSumSubset(a, n) << endl;
    }
    return 0;
}