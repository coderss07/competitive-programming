// Author : Sarthak Sharma
// Date: 2021-11-07 14:24

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

// void solve(int tc) {
// 	int n; cin >> n;
//     vl a(n);
//     rep(i, 0, n) {
//         cin >> a[i];
//     }
//     ll x = 0;
//     rep(i, 0, 63) {
//        	ll tmp = ((ll)1 << i);
//        	ll cnt = 0;
//         rep(i, 0, n) {
//             if((a[i] + x) & tmp) cnt++;
//         }
//         if(cnt % 2 != 0) {
//             x = x | tmp;
//         }
//     }
//     ll xor_sum = 0;
//     rep(i, 0, n) xor_sum ^= (a[i] + x);
//     if(xor_sum == 0 && x != INT64_MAX) {
//     	cout << x << endl;
//     	return;
//     }
//     cout << -1 << endl;
// }

void solve(int tc) {
	string s;
	cin >> s;
	vi cnt;
	int tmp = 1;
	rep(i, 1, s.size()) {
		if(s[i] != s[i - 1]) cnt.pb(tmp), tmp = 1;
		else tmp++;
	}
	cnt.pb(tmp);

	for(auto it: cnt) cerr << it << tab1;
	cerr << endl;

	ll res;
	
	res = 0;
	int n = cnt.size();
	for(int i = 1; i < n - 1; i += 2) {
		if(i < n - 2 && cnt[i + 1] == 1) {
			res++;
		}else if(cnt[i] > 1) {
			res += 2;
		}else {
			res++;
		}
	}
	
		
	ll ans = 0;
	for(int i = 0; i < n; i += 2) {
		if(i < n - 1 && cnt[i + 1] == 1) {
			ans++;
		}else if(cnt[i] > 1) {
			ans += 2;
		}else {
			ans++;
		}
	}
	
	res = min(res, ans);
	cout << res << endl;
}

int main() {
  clock_t begin_69 = clock();
  fast_io;
  int t; cin >> t;
  while(t--) solve(t);
    
  #ifndef ONLINE_JUDGE
    clock_t terminator_69 = clock();
    cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
  #endif 
  return 0;
}