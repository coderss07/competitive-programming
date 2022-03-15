// Author : Sarthak Sharma
// Date: 2022-02-17 15:50:55

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab1 " "
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define lb lower_bound
#define up upper_bound
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)
#define fbo find_by_order
#define oof order_of_key
#define all(a) a.begin(), a.end()

using namespace std;
using namespace __gnu_pbds;

// <------------------------------------- Templates ------------------------------------->
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using maxh = priority_queue<T>;
template <class T> using minh = priority_queue<T, vector<T>, greater<T>>;

template <class T> void _print(T arg) { cerr << arg << endl; }

template <class T> void _print(vector<T> &a) { for(auto &it: a) { cerr << it << tab1; }cerr << endl; }

template <class T> void _input(T &a) { cin >> a; }

template <class T> void _input(T &a, int n) { for(auto &it: a) { cin >> it; } }

// <------------------------------------- Code ------------------------------------->

// const int N = 1e5 + 10;
// const int mod = 1e9;

int dp[2002][2002][6];

int LCS(vi& a, vi& b, int n, int m, int k) {
	if(n < 0 || m < 0) return 0;
	if(dp[n][m][k] != -1) return dp[n][m][k];
	int ans = 0;
	if(a[n] == b[m]) ans = 1 + LCS(a, b, n - 1, m - 1, k);
	if(k > 0) ans = max(ans, LCS(a, b, n - 1, m - 1, k - 1) + 1);
	dp[n][m][k] = max({ans, LCS(a, b, n - 1, m, k), LCS(a, b, n, m - 1, k)});
	return dp[n][m][k];
}

void solve(int tt) {
	int n, m, k; cin >> n >> m >> k;
	vi a(n), b(m);
	mem1(dp);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];

	cout << LCS(a, b, n - 1, m - 1, k);
}

int main() {
	clock_t begin_69 = clock();
	fast_io;

	// int t; cin >> t;
	int t = 1;
	while(t--) {
		solve(t);
	}
	
	#ifndef ONLINE_JUDGE
		clock_t terminator_69 = clock();
		cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	#endif 
	return 0;
}