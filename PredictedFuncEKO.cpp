#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define pi pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

const int N = 1e6;
int n;
ll m;
vi tree;

bool isWoodSufficient(int h) {
    ll wood = 0;
    rep(i, 0, n) {
        if(tree[i] >= h)
            wood += (tree[i] - h);
    }

    return wood >= m;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    cin >> n >> m;
    tree = vi(n);
    rep(i, 0, n) cin >> tree[i];

    ll lo = 0, hi = 1e9, mid;
    while(hi - lo > 1) {
        mid = (hi + lo) / 2;
        if(isWoodSufficient(mid)) {
            lo = mid;
        }else {
            hi = mid - 1;
        }
    }
    if(isWoodSufficient(hi)) {
        cout << hi << endl;
    }else {
        cout << lo << endl;
    }

    return 0;
}