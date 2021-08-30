#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

const int N = 1e3 + 10;
vector< vector<int> > dp;

int coin_change(vector<int> &a, int n, int x) {
	if (x < 0 || n <= 0) return 0;

	if(x == 0) return 1;

	if (dp[n][x] != -1)
		return dp[n][x];

	dp[n][x] = (coin_change(a, n - 1, x) + coin_change(a, n, x - a[n - 1]));
	return dp[n][x];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		rep(i, 0, n) {
			cin >> a[i];
		}

		// vector<int> dp(x + 1, 0);
		// dp[0] = 1;
		// for (auto &it : a) {
		// 	rep(i, it, x + 1) {
		// 		dp[i] += dp[i - it];
		// 	}
		// }
		// cout << dp[x] << endl;

		dp = vector<vector<int>>(n + 1, vector<int>(x + 1, -1));
		cout << coin_change(a, n, x) << endl;
		// cout<< dp[x] <<endl;
	}
	return 0;
}
