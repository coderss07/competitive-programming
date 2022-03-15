// Author : Sarthak Sharma
// Date: 2022-03-09 19:08:28

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int, int>
#define vpi vector<pii>
#define ff first
#define ss second
#define pb push_back
#define bitcnt1 __builtin_popcount
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab1 " "
#define lb lower_bound
#define up upper_bound
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)
#define fbo find_by_order
#define oof order_of_key
#define all(a) a.begin(), a.end()
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))

using namespace std;
using namespace __gnu_pbds;

// <------------------------------------- Templates ------------------------------------->
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using maxh = priority_queue<T>;
template <class T> using minh = priority_queue<T, vector<T>, greater<T>>;

template <class T> void _print(T arg) { cerr << arg << endl; }

template <class T> void _print(vector<T> &a) { for(auto &it: a) { cerr << it << tab1; }cerr << endl; }

template <class T> void read(T &a) { for(auto &it: a) { cin >> it; } }
template <class T> void print(T &a) { for(auto &it: a) cout << it << tab1; cout << endl; }

// <------------------------------------- Math ------------------------------------->
template <class T> T add_mod(T a, T b, ll mod = 1e9 + 7) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
template <class T> T mul_mod(T a, T b, ll mod = 1e9 + 7) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
template <class T> T sub_mod(T a, T b, ll mod = 1e9 + 7) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}

template <class T> T lcm(T a, T b) { return (a * b) / __gcd(a, b); }
template <class T> T binMul(T a, T b, ll mod = 1e9 + 7) { T ans = 0; while(b) { if(b & 1) { ans = add_mod(ans, a); } a = add_mod(a, a); b >>= 1; } return ans; }
template <class T> T _pow(T a, T b, ll mod = 1e9 + 7) { T ans = 1; while(b) { if(b & 1) ans = binMul(ans, a); a = binMul(a, a); b >>= 1; } return ans; }
template <class T> T ceilDivision(T a, T b) { return (a + b - 1) / b; }

vll sieve(int n) { vll a(n + 1, 1); a[0] = a[1] = 0; vll ans; for(ll i = 2; i * i <= n; i++) if(a[i] == 1) { ans.pb(i); for(int j = 2 * i; j <= n; j += i) a[j] = 0; } for(int i = sqrt(n); i <= n; i++) if(a[i] == 1) ans.pb(i); return ans; }
bool isPrime(ll n) { for(ll i = 2; i * i <= n; i++) if(n % i == 0) return 0; return 1; }


// <------------------------------------- Code ------------------------------------->
// const int N = 1e5 + 10;
const int mod = 1e9 + 7;

map<pair<int, ll>, int> dp;

int calc(vll& a, int n, ll p, int k) {
	if(n <= 0)
		return ((p % 10) == k);
	if(dp.find({n, p}) != dp.end()) return dp[{n, p}];
	dp[{n, p}] = (calc(a, n - 1, p * 1LL * a[n - 1], k) % mod + calc(a, n - 1, p, k) % mod) % mod;
	return dp[{n, p}];
}

void solve(int tt) {
	int n, k; cin >> n >> k;
	vll a(n);
	rep(i, 0, n) cin >> a[i];
	// rep(i, 0, n) cin >> b[i];
	ll ans = calc(a, n, 1, k);

	cout << ans << endl;
}

int main() {
	clock_t begin_69 = clock();
	fast_io;

	int t = 1;
	cin >> t; 
	while(t--) {
		solve(t);
	}
	
	#ifndef ONLINE_JUDGE
		clock_t terminator_69 = clock();
		cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	#endif 
	return 0;
}