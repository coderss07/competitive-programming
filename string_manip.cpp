// Author : Sarthak Sharma
// Date: 2022-02-06 19:32:56

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

string res = "";
int fval = INT_MAX;

void solve(string s, string tmp, int val) {
	if(s.size() == 0) {
		if(val < fval) {
			fval = val;
			res = tmp;
		}
		return;
	}
	if(s.size() == 1) {
		if(val + int(s[0]) < fval) {
			fval = val + int(s[0]);
			res = tmp + s[0];
		}
		return;
	}
	if(s[0] + 1 == s[1]) {
		solve(s.substr(2), tmp + char(s[1] + 1), val + s[0] +1);
	}
	solve(s.substr(1), tmp + s[0], val + s[0]);
}

int main() {
	clock_t begin_69 = clock();
	fast_io;

	string s; cin >> s;
	solve(s, "", 0);
	cout << res << endl;
	_print(fval);
	
	#ifndef ONLINE_JUDGE
		clock_t terminator_69 = clock();
		cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	#endif 
	return 0;
}
