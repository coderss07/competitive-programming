#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define pi pair<int, int>
#define ff first
#define ss second
#define fast_io ios_base::sync_with_stdio(false); cin .tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

int n, k;
vi algo;
vi sleep;

int solve() {
    vi pref(n);
    vi all(n);
    vi suff(n);
    pref[0] = algo[0] * sleep[0];
    all[0] = algo[0];
    suff[n - 1] = algo[n - 1] * sleep[n - 1];
    rep(i, 1, n) {
        pref[i] = pref[i - 1] + (algo[i] * sleep[i]);
        all[i] = all[i - 1] + algo[i];
    }
    rrep(i, n - 1, 0) {
        suff[i] = suff[i + 1] + (algo[i] * sleep[i]);
    }
    int ans = 0;
    for(int i = 0; i + k - 1 < n; i++) {
        int curr = 0;
        if(i > 0) {
            curr += pref[i - 1];
        }
        if(i + k < n) {
            curr += suff[i + k];
        }
        curr += all[i + k - 1];
        if(i > 0) {
            curr -= all[i - 1];
        }
        ans = max(ans, curr);
    }

    return ans;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    cin >> n >> k;
    algo = vi(n);
    sleep = vi(n);
    rep(i, 0, n) cin >> algo[i];

    rep(i, 0, n) cin >> sleep[i];
    cout << solve() << endl;
    return 0;
}