#include<bits/stdc++.h>

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
#define lb lower_bound
#define up upper_bound
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1e6 + 1;
const int mod = 1e9 + 7;


// void solve() {
//     cin >> s;
//     int q; cin >> q;
//     calc();
//     while(q--) {
//         int l, r;
//         cin >> l >> r;

//     }cout << endl;
// }

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int t;
    cin >> t;
    while(t--) solve(t);
    #ifndef ONLINE_JUDGE
          clock_t terminator_69 = clock();
          cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif
    return 0;
}