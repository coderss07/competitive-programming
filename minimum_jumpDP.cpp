#include<bits/stdc++.h>
#define vi vector<int>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

const int N = 1e7;

int main() {
    int n; cin >> n;
    vi a(n);

    rep(i, 1, n) cin >> a[i];

    vi dp(n, N); dp[1] = 0;

    rep(i, 1, n) {
        rep(j, 0, i) {
            if(j + a[j] >= i) {
                dp[i] = min(dp[i], dp[j] + 1);
				break;
            }
        }
    
    }

    cout << dp[n - 1] << endl;

    return 0;
}