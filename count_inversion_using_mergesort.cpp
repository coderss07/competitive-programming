// Author : Sarthak Sharma
// Date: 2021-10-24 16:50

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

int merge(vi& a, int l, int m, int r) {
	int ans = 0;
	int i = l;
	int j = m + 1;
	vi b(r - l + 1);
	int k = 0;
	while(i <= m && j <= r) {
		if(a[i] <= a[j]) {
			b[k++] = a[i++];
		}else {
			b[k++] = a[j++];
			ans += m - l + 1 - i;
		}
	}
	while(i <= m) b[k++] = a[i++];
	while(j <= r) b[k++] = a[j++];
	return ans;
}

int merge_sort(vi &a, int l, int r) {
	int ans = 0;
	if(l < r) {
		int mid = (l + r) / 2;
		ans += merge_sort(a, l, mid);
		ans += merge_sort(a, mid + 1, r);
		ans += merge(a, l, mid, r);
	}

	return ans;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) {
    	cin >> a[i];
    }
    
    cout << merge_sort(a, 0, n - 1) << endl;
    
    #ifndef ONLINE_JUDGE
          clock_t terminator_69 = clock();
          cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif 
    return 0;
}