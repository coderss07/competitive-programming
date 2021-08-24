#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector< vector<int> >
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

vvi dp;

int LCS(string s1, string s2, int n, int m) {
    if(n == 0 || m == 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n - 1] == s2[m - 1])
        dp[n][m] = 1 + LCS(s1, s2, n - 1, m - 1);
    else
        dp[n][m] = max(LCS(s1, s2, n - 1, m), LCS(s1, s2, n, m - 1));

    return dp[n][m];
}

int32_t main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    dp = vvi(n + 1, vi(m + 1, -1));

    cout << LCS(s1, s2, n, m) << endl;

    return 0;
}