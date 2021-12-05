// Author : Sarthak Sharma
// Date: 2021-11-22 18:00

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

template <class T> void _print(T arg) { cerr << arg << endl; }

template <class T> void _print(vector<T> &a) { for(auto &it: a) { cerr << it << tab1; }cerr << endl; }

// <------------------------------------- Code ------------------------------------->

const int N = 1e5 + 10;
const int mod = 1e9;

vvi adj;
int n;
vi vis;
vvi dp;

int TSP(int node, int cnt) {
	if(cnt == n - 1 && adj[node][1]) {
		return adj[node][1];
	}
	if(dp[node][cnt] != -1) {
		return dp[node][cnt];
	}
	dp[node][cnt] = N;
	rep(i, 1, n) {
		if(!vis[i] && adj[node][i]) {
			vis[i] = 1;
			dp[node][cnt] = min(dp[node][cnt], TSP(i, cnt + 1) + adj[node][i]);
			vis[i] = 0;
		}
	}
	return dp[node][cnt];
}

int main() {
	clock_t begin_69 = clock();
	fast_io;
	cin >> n;
	n++;
	adj = vvi(n, vi(n));
	dp = vvi(n, vi(n, -1));
	rep(i, 1, n) {
		rep(j, 1, n) {
			cin >> adj[i][j];
		}
	}
	vis = vi(n, 0);
	vis[1] = 1;

	cout << TSP(1, 1) << endl;
	
	#ifndef ONLINE_JUDGE
		clock_t terminator_69 = clock();
		cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	#endif 
	return 0;
}