#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>

using namespace std;

int main() {
    int n; cin >> n;
    string s;
    cin >> s;

    int e = 1;
    int a = 0;
    int ab = 0;
    int abc = 0;

    rep(i, 0, n) {
        if(s[i] == 'a') {
            a += e;
        }else if(s[i] == 'b') {
            ab += a;
        }else if(s[i] == 'c') {
            abc += ab;
        }else if(s[i] == '?') {
            abc = 3 * abc + ab;
            ab = 3 * ab + a;
            a = 3 * a + e;
            e = 3 * e;
        }
    }
    cout << e << endl;
    cout << a << endl;
    cout << ab << endl;

    cout << abc << endl;
    return 0;
}