// Author : Sarthak Sharma
// Date: 2021-10-10 15:40:32
#include<bits/stdc++.h>
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

// <------------------------------------- Code ------------------------------------->

const int N = 1e5;
const int mod = 1000000007;
vl tree(4 * N, 0);
vl a;

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    //changed according to need
    // tree[node] = (tree[2 * node], tree[2 * node + 1])
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

ll query(int node, int start, int end, int l, int r) {
    if(start > r || end < l) {
        // start......end....l.....r
        return -mod;
    }
    if(start >= l && end <= r) {
        //l.....start.......end.....r
        return tree[node];
    }
    // start.....l.....end.....r
    // l.....start.....r.....end
    int mid = (start + end) / 2;
    ll lc = query(2 * node, start, mid, l, r);
    ll rc = query(2 * node + 1, mid + 1, end, l, r);

    return max(lc, rc);
}

void update(int node, int start, int end, int idx, ll val) {
    if(start == end) {
        a[start] = val;
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) {
        update(2 * node, start, mid, idx, val);
    }else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
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
            ll x;
            cin >> x;
            int l = 0, h = n - 1;
            int ans = n;

            while(l <= h) {
                int mid = (l + h) / 2;
                if(query(1, 0, n - 1, l, mid) < x) {
                    l = mid + 1;
                }else {
                    h = mid - 1;
                    ans = min(ans, mid);
                }
            }
            cout << (ans == n ? -1 : ans) << endl;
            // cout << query(1, 0, n - 1, 0, 2) << endl;
            // if(ans == n) cout << -1 << endl;
            // else cout << ans << endl;
        }
    }

    return 0;
}