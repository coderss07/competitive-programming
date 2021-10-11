// Author : Sarthak Sharma
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
#define N 1e5
#define mod 1000000007
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

// <------------------------------------- Code ------------------------------------->

ll solve() {
    string str; cin >> str;
    char d; cin >> d;
    string s = str;
    int n = s.size();
    rrep(i, n, 0) {
        if(s[i] == d) {
            int pos = n - i - 1;
            int tmp = 1;
            while(pos--) {
                tmp *= 10;
            }
            ll add = 0;
            if(i == n - 1) {
                add++;
            }else {
                ll j = stol(s.substr(i + 1));
                add = (tmp - j);
            }
            ll j = stol(s);
            j += add;
            if(i != n - 1 && d == '0') {
                pos = n - i - 2;
                tmp = 1;
                while(pos--) {
                    tmp = tmp * 10 + 1;
                }
                j += tmp;
            }
            s = to_string(j);
        }
    }
    return (stol(s) - stol(str));

}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int t; cin >> t;
    while(t--) {
        cout << solve() << endl;
    }

    return 0;
}