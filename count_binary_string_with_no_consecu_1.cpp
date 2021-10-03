#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)


using namespace std;

int main() {
    int n; cin >> n;
    int cnt0 = 1;
    int cnt1 = 1;

    rep(i, 2, n + 1) {
        int new0 = cnt0 + cnt1;
        int new1 = cnt0;

        cnt0 = new0;
        cnt1 = new1;
    }

    cout << cnt0 + cnt1 << endl;

    return 0;
}