// Author : Sarthak Sharma
// Date : 2021-10-10 12:45:14
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab1 " "
#define vvi vector<vector<int>>
#define tab " "
#define vpi vector<pii>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

// <------------------------------------- Code ------------------------------------->
const int N = 1e5;
const int mod = 1000000007;
vpi tree(4 * N, {0, 0});
vl a;

void build(int node, int start, int end) {
    if(start == end) {
        tree[node].ff = a[start];
        tree[node].ss = 1;
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    
    if(tree[2 * node].ff > tree[2 * node + 1].ff) {
        tree[node] = tree[2 * node + 1];
    }else if(tree[2 * node].ff < tree[2 * node + 1].ff) {
        tree[node] = tree[2 * node];
    }else {
        tree[node].ff = tree[2 * node].ff;
        tree[node].ss = tree[2 * node].ss + tree[2 * node + 1].ss;
    }
}

pii query(int node, int start, int end, int l, int r) {
    if(start > r || end < l) {
        // start......end....l.....r
        return make_pair(mod, -1);
    }
    if(start >= l && end <= r) {
        //l.....start.......end.....r
        return tree[node];
    }
    // start.....l.....end.....r
    // l.....start.....r.....end
    int mid = (start + end) / 2;
    pii lc = query(2 * node, start, mid, l, r);
    pii rc = query(2 * node + 1, mid + 1, end, l, r);
    if(lc.ff < rc.ff) {
        return lc;
    }else if(rc.ff < lc.ff) {
        return rc;
    }else {
        return make_pair(lc.ff, lc.ss + rc.ss);
    }
}

void update(int node, int start, int end, int idx, ll val) {
    if(start == end) {
        a[start] = val;
        tree[node].ff = val;
        tree[node].ss = 1;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) {
        update(2 * node, start, mid, idx, val);
    }else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    
    if(tree[2 * node].ff > tree[2 * node + 1].ff) {
        tree[node] = tree[2 * node + 1];
    }else if(tree[2 * node].ff < tree[2 * node + 1].ff) {
        tree[node] = tree[2 * node];
    }else {
        tree[node].ff = tree[2 * node].ff;
        tree[node].ss = tree[2 * node].ss + tree[2 * node + 1].ss;
    }
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int n, m;
    cin >> n >> m;
    a = vl(n);
    rep(i, 0, n) cin >> a[i];
    build(1, 0, n - 1);
    while(m--) {
        int type; cin >> type;
        if(type == 1) {
            int idx;
            ll value;
            cin >> idx >> value;
            update(1, 0, n - 1, idx, value);
        }else if(type == 2) {
            int l, r;
            cin >> l >> r;
            pii p = query(1, 0, n - 1, l, r - 1);
            cout << p.ff << tab1 << p.ss << endl;
        }
    }

    return 0;
}