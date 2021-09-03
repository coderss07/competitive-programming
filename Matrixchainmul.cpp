#include<bits/stdc++.h>
#define ll long long int
#define vvi vector< vector<int > >
#define vi vector< int >
#define rep(i,a,b) for(int i = a; i < b; i++)

using namespace std;

const int N = 1e2;
vvi dp;

int Matrix_chainMul(vi &a, int i, int j) {
    if(i == j) return 0;

    if(dp[i][j] != -1) { return dp[i][j]; }

    dp[i][j] = INT_MAX;

    rep(k, i, j) {
        dp[i][j] = min(dp[i][j], Matrix_chainMul(a, i, k) + Matrix_chainMul(a, k + 1, j) + ( a[i-1] * a[k] * a[j]));
    }
    return dp[i][j];
}

int main() {
	int n; cin >> n;o
    vi a(n);

    dp = vvi(N, vi(N, -1));
    
    rep(i, 0, n) {
        cin >> a[i];
    }
	
    cout << Matrix_chainMul(a, 1, n - 1) << endl;

	return 0;
}