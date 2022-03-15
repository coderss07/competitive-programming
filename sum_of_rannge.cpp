// Author : Sarthak Sharma
// Date: 2022-02-12 11:55:29

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

void solve(int tt) {
	int n; cin >> n;
	vi nums(n);
	rep(i, 0, n) {
		cin >> nums[i];
	}

	// vector<vector<pii>> dp(n, vector<pii>(n));
	// int sum = 0;
	// rep(gap, 0, n) {
	// 	int i = 0, j = gap;
	// 	while(j < n) {
	// 		if(gap == 0) {
	// 			dp[i][j] = mp(a[i], a[i]);
	// 		}else if(gap == 1) {
	// 			dp[i][j] = mp(min(a[i], a[j]), max(a[i], a[j]));
	// 		}else {
	// 			dp[i][j].ff = min(dp[i + 1][j - 1].ff, min(a[i], a[j]));
	// 			dp[i][j].ss = max(dp[i + 1][j - 1].ss, max(a[i], a[j]));
	// 		}
	// 		sum += (dp[i][j].ss - dp[i][j].ff);
	// 		i++, j++;
	// 	}
	// }
	// cout << sum << endl;


	vector<int> maxr(n), minr(n);
	stack<int> minSt, maxSt;
	for(int i = n - 1; i >= 0; i--) {
		while(!maxSt.empty() && nums[maxSt.top()] < nums[i]) maxSt.pop();
		if(maxSt.empty()) maxr[i] = n - i;
		else maxr[i] = maxSt.top() - i;
		while(!minSt.empty() && nums[minSt.top()] > nums[i]) minSt.pop();
		if(minSt.empty()) minr[i] = n - i;
		else minr[i] = minSt.top() - i;
		maxSt.push(i);
		minSt.push(i);
	}
	while(!maxSt.empty()) maxSt.pop();
	while(!minSt.empty()) minSt.pop();
	ll maxAns = 0, minAns = 0;
	for(int i = 0; i < n; i++) {
		while(!maxSt.empty() && nums[maxSt.top()] < nums[i]) maxSt.pop();
		if(maxSt.empty()) maxAns += (nums[i] * (maxr[i] * (i + 1)));
		else maxAns += (nums[i] * (maxr[i] * (i - maxSt.top())));
		while(!minSt.empty() && nums[minSt.top()] > nums[i]) minSt.pop();
		if(minSt.empty()) minAns += (nums[i] * (minr[i] * (i + 1)));
		else minAns += (nums[i] * (minr[i] * (i - minSt.top())));
		maxSt.push(i);
		minSt.push(i);
	}
	cout << maxAns - minAns << endl;

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