// Author : Sarthak Sharma
// Date: 2022-01-16 19:30:02

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define el __int128_t
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

void add(vi& a, vi b) {
	if(a.empty()) {
		a = b;
		return;
	}
	int n = a.size();
	int m = b.size();
	if(m > n) {
		rep(i, 0, (m - n)) a.pb(0);
		n = m;
	}
	int rem = 0, i = 0;
	while(i < m) {
		a[i] += (b[i] + rem);
		if(a[i] >= 6) {
			a[i] %= 6;
			rem = 1;
		}else rem = 0;
		i++;
	}
	if(rem) {
		if(i < n) a[i] += 1;
		else a.pb(1);
	}
}

vi solve(vi &a, int n) {
	vi ans;
	rep(i, 0, n) {
		if(a[i] == 0) continue;
		el a = pow(2, i);
		vi tmp;
		while(a) {
			int rem = a % 6;
			tmp.pb(rem);
			a /= 6;
		}
		add(ans, tmp);
		_print(ans);
	}
	return ans;
}

int main() {
	clock_t begin_69 = clock();
	fast_io;
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	vi ans = solve(a, n);
	for(auto it: ans) cout << it << tab1;
	
	#ifndef ONLINE_JUDGE
		clock_t terminator_69 = clock();
		cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	#endif 
	return 0;
}