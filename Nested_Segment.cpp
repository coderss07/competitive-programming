// Author : Sarthak Sharma
// Date: 2021-10-20 17:21:59

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

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

using namespace std;
// using namespace __gnu_pbds;

// <------------------------------------- Templates ------------------------------------->
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <class K, class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> void _print(T arg) { cerr << arg << endl; }

template <class T> void _print(vector<T> &a) { for(auto &it: a) { cerr << it << tab1; }cerr << endl; }

// <------------------------------------- Code ------------------------------------->

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

struct trip {
    int l, r, idx;
};

int n;
vector<trip> t;
vi tr(8 * N, 0);

int query(int node, int start, int end, int l, int r) {
    if(start > r || end < l) {
        // start......end....l.....r
        return 0;
    }
    if(l <= start && end <= r) {
        //l.....start.......end.....r
        return tr[node];
    }
    // start.....l.....end.....r
    // l.....start.....r.....end
    int mid = (start + end) / 2;
    int lc = query(2 * node, start, mid, l, r);
    int rc = query(2 * node + 1, mid + 1, end, l, r);

    return lc + rc;
}

void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
        tr[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) {
        update(2 * node, start, mid, idx, val);
    }else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    tr[node] = tr[2 * node] + tr[2 * node + 1];
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    cin >> n;
    
    t = vector<trip>(n, {-1, -1});
    rep(i, 0, 2 * n) {
        int x;
        cin >> x;
        if(t[x - 1].l == -1) {
            t[x - 1].l = i;
        }else {
            t[x - 1].r = i;
        }
        t[x - 1].idx = x;
        // _print(x);
    }
    sort(t.begin(), t.end(), [&](trip a, trip b){
        return a.r < b.r;
    });
    // for(auto &it: t) {
    //     cerr << it.l << tab1 << it.r << tab1 << it.idx << endl;
    // }

    vi ans(n);
    rep(i, 0, n) {
        ans[t[i].idx - 1] = query(1, 0, 2 * n - 1, t[i].l, t[i].r);
        update(1, 0, 2 * n - 1, t[i].l, 1);
    }

    rep(i, 0, n) {
        cout << ans[i] << tab1;
    }cout << endl;
    
    #ifndef ONLINE_JUDGE
        clock_t terminator_69 = clock();
        cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms";
    #endif
    return 0;
}