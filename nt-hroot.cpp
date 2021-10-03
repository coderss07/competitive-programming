#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define pi pair<int, int>
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

const double eps = 1e-6;

int main() {
    double n; cin >> n;
    double l = 1, h = n;
    while(h - l > eps) {
        double m = (h + l) / 2;
        if(m * m * m < n) {
            l = m;
        }else {
            h = m;
        }
    }
    cout << h << endl;
    return 0;
}