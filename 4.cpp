// Author : Sarthak Sharma
// Date: 2022-02-16 20:01:19

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
	string x, y; cin >> x >> y;
	string ans(2 * n, ' ');
	sort(all(x));
	sort(all(y), greater<char>());
	int l = 0, r = 2 * n - 1;
	int i = 0, j = 0;
	while (l < r) {
		if(x[i] < y[j]) {
			ans[l] = x[i];
			i++;
			l++;
		}else {
			ans[r] = x.back();
			x.pop_back();
			r--;
		}
		if(x.size() == 0 || x[i] < y[j]) {
			ans[l] = y[j];
			l++;
			j++;
		}else {
			ans[r] = y.back();
			y.pop_back();
			r--;
		}
	}
	cout << ans << endl;
}

int main() {
	clock_t begin_69 = clock();
	fast_io;

	int t; cin >> t;
	// int t = 1;
	while(t--) {
		solve(t);
	}
	
	#ifndef ONLINE_JUDGE
		clock_t terminator_69 = clock();
		cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	#endif 
	return 0;
}