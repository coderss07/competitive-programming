// Author : Sarthak Sharma
#include<bits/stdc++.h>
//<------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
#define N 100000
#define mod 1000000007
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab " "
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vc vector<char>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

//<------------------------------------- Code ------------------------------------->

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vi ans;

    rep(i, 0, n) {
        rep(j, i, n) {
            if(j - i + 1 == 1) {
                if(a[i] != 0) ans.push_back(0);
                else ans.push_back(1);
                continue;
            }
            unordered_set<int> tmp;
            rep(l, i, j + 1) {
                tmp.insert(a[l]);
            }
            int m = tmp.size();
            m = (m * (m + 1)) / 2;
            for(auto it: tmp) m -= it;
            cerr << m << endl;
            ans.push_back(m);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[k - 1] << endl;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}