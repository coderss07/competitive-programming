// Author : Sarthak Sharma

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
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)
#define fbo find_by_order
#define oof order_of_key

using namespace std;
using namespace __gnu_pbds;

// <------------------------------------- Templates ------------------------------------->
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

// <------------------------------------- Code ------------------------------------->
const int N = 1e7 + 1;

vector<pii> dp(N, {0, 1});

void calc() {
	dp[0] = {0, 0};
	dp[1] = {0, 0};
	for(int i = 2; i * i <= N; i++) {
		dp[i].ff = dp[i - 1].ff;
		if(dp[i].ss == 1) {
			for(int j = i * i; j <= N; j += i) {
				dp[j].ss = 0;
			}
			dp[i].ff++;
		}
	}
	int i = sqrt(N);
	for(; i <= N; i++) {
		dp[i].ff = dp[i - 1].ff;
		if(dp[i].ss == 1) dp[i].ff++;
	}
}

void solve() {
	int x, y;
	cin >> x >> y;
	int ans = y - x;
	int no_of_p = dp[y].ff - dp[x].ff;
	cerr << dp[y].ff << tab1 << dp[x].ff << endl;
	ans -= no_of_p;
	if(dp[x + 1].ss == 1)
		ans++;
	cout << ans << endl;
	
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int t;
    cin >> t;
    calc();
    while(t--) {
    	solve();
	}
	 
    #ifndef ONLINE_JUDGE
          clock_t terminator_69 = clock();
          cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif 
    return 0;
}
