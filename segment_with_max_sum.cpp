// Author : Sarthak Sharma
// Date: 
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
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
vvl tree(4 * N, vl(4, 0)); // {sum, pref, suff, ans}
vl a;

void build(int node, int start, int end) {
    if(start == end) {
        if(a[start] < 0) {
            tree[node] = {a[start], 0, 0, 0};
        }else {
            tree[node] = {a[start], a[start], a[start], a[start]};
        }
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    //changed according to need
    // tree[node] = (tree[2 * node], tree[2 * node + 1])
    ll sum = tree[2 * node][0] + tree[2 * node + 1][0];
    ll pref = max(tree[2 * node][1], tree[2 * node][0] + tree[2 * node + 1][1]); // pref = max(left.pref, left.sum + right.pref)
    ll suff = max(tree[2 * node + 1][2], tree[2 * node + 1][0] + tree[2 * node][2]); // suff = max(right.suff, right.sum + left.suff)
    ll ans = max(tree[2 * node][2] + tree[2 * node + 1][1], max(tree[2 * node][3], tree[2 * node + 1][3])); // ans = max(left.suff + right.pref, left.ans, right.ans)
    tree[node] = {sum, pref, suff, ans};
}

void update(int node, int start, int end, int idx, ll val) {
    if(start == end) {
        a[start] = val;
        if(val < 0) {
            tree[node] = {a[start], 0, 0, 0};
        }else {
            tree[node] = {a[start], a[start], a[start], a[start]};
        }
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) {
        update(2 * node, start, mid, idx, val);
    }else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }

    ll sum = tree[2 * node][0] + tree[2 * node + 1][0];
    ll pref = max(tree[2 * node][1], tree[2 * node][0] + tree[2 * node + 1][1]); // pref = max(left.pref, left.sum + right.pref)
    ll suff = max(tree[2 * node + 1][2], tree[2 * node + 1][0] + tree[2 * node][2]); // suff = max(right.suff, right.sum + left.suff)
    ll ans = max(tree[2 * node][2] + tree[2 * node + 1][1], max(tree[2 * node][3], tree[2 * node + 1][3])); // ans = max(left.suff + right.pref, left.ans, right.ans)
    tree[node] = {sum, pref, suff, ans};
    
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int n, m;
    cin >> n >> m;
    a = vl(n);
    rep(i, 0, n) cin >> a[i];
    build(1, 0, n - 1);
    cout << tree[1][3] << endl;
    while(m--) {
        int idx;
        ll value;
        cin >> idx >> value;
        update(1, 0, n - 1, idx, value);
        cout << tree[1][3] << endl;
    }
    return 0;
}