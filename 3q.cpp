// Author : Sarthak Sharma
// Date: 2022-03-08 20:39:11

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>

// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab1 " "

using namespace std;
// <------------------------------------- Code ------------------------------------->

// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;

int sum = 1e8;

// map<pair<int, int>, int> dp;

int solve(vector<int>& a, int n, int i, int m1, int m2) {
	if(i >= n) {
		return 0;
	}
	// if(dp.find({sum1, sum2}) != dp.end()) ;
	
	int x = max(a[i] + solve(a, n, i + 1, m1, m2), solve(a, n, i + 1, m1, m2));
	int y = max(a[i] + solve(a, n, i + 1, m1, m2), solve(a, n, i + 1, m1, m2));
	return min(x, y);
}

void solve(int tt) {
	int m1, m2; cin >> m1 >> m2;
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sum = solve(a, n, 1, m1, m2);
	// if(m1 > m2) swap(m1, m2);
	// if(sum1 < sum2) swap(sum1, sum2);
	// ll ans = max(sum1 * m1, sum2 * m2);
	cout << sum << endl;
	
}

int main() {
	fast_io;

	int t = 1;
	// cin >> t; 
	while(t--) {
		solve(t);
	}

	return 0;
}
