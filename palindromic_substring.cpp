#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define pi pair<int, int>
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

vvi hsh;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    hsh = vvi(n + 1, vi(26, 0));
    rep(i, 1, n + 1) {
        hsh[i][s[i - 1] - 'a']++;
    }
    rep(i, 0, 26) {
        rep(j, 1, n + 1) {
            hsh[j][i] += hsh[j - 1][i];
        }
    }
    int q; cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int oddcnt = 0;
        rep(i, 0, 26) {
            int chcnt = hsh[r][i] - hsh[l - 1][i];
            if(chcnt % 2 != 0) {
                oddcnt++;
            }
        }
        if(oddcnt <= 1) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }

    return 0;
}