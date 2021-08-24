#include <bits/stdc++.h>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

const int N =  1e6 + 5;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> hsh(N,0);
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, 0, n) {
            cin >> a[i];
            hsh[a[i]] ++;
        }
        int k;
        cin >> k;

        int cnt = 0;

        rep(i,0,n) {
            hsh[a[i]]--;
            if(hsh[(a[i] + k)]) {
                cnt++;
            }
            if(k)
                hsh[a[i]]++;
        }

        cout << cnt << endl;
        

    }
    return 0;
}
