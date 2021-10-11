// Author : Sarthak Sharma
// Date: 2021-10-10 15:40:42
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
vi tree(4 * N, 0);
vi a;

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
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int k) {
    if(start == end) {
        return start;
    }
    int mid = (start + end) / 2;
    if(k < tree[2 * node]) {
        return query(2 * node, start, mid, k);
    }else {
        return query(2 * node + 1, mid + 1, end, k - tree[2 * node]);
    }

}

void update(int node, int start, int end, int idx) {
    if(start == end) {
        a[start] = a[start] ^ 1;
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) {
        update(2 * node, start, mid, idx);
    }else {
        update(2 * node + 1, mid + 1, end, idx);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int n, m; cin >> n >> m;
    a = vi(n);
    rep(i, 0, n) cin >> a[i];
    build(1, 0, n - 1);
    while(m--) {
        int type; cin >> type;
        if(type == 1) {
            int idx; cin >> idx;
            update(1, 0, n - 1, idx);
        }else if(type == 2) {
            int k; cin >> k;
            cout << query(1, 0, n - 1, k) << endl;
        }
    }

    return 0;
}