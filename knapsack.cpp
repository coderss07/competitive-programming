#include<bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i < b; i++)

using namespace std;
const int N = 1e3 + 10;

vector<vector< int > > dp;

int knapSack(vector<int> &val, vector<int> &wt, int n, int W){
	if(n<=0 || W<=0){
		return 0;
	}
	if(dp[n][W] != -1) {
		return dp[n][W];
	}
	if(wt[n - 1] > W){
		dp[n][W] = knapSack(val,wt,n-1,W);
	}else {
		dp[n][W] = max( knapSack(val,wt,n-1,W) , (knapSack(val,wt,n-1,W-wt[n - 1]) + val[n - 1]) );
	}
	return dp[n][W];
}

int main() {
	int n; cin >> n;
	vector<int> val(n);
	vector<int> wt(n);
	rep(i,0,n) {
		cin >> val[i];
	}

	rep(i,0,n) {
		cin >> wt[i];
	}
	int W; cin >> W;
	dp = vector< vector<int> >(n+1, vector<int>(N, -1));

	cout<< knapSack(val,wt,3,W) << "\n";
	return 0;
}
