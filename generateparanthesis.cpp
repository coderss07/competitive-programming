#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>

using namespace std;

void generateParanthesis(string &s, int open, int close) {
    if(open == 0 && close == 0) {
        cout << s << " ";
        return;
    }

    if(open > 0) {
        s.push_back('(');
        generateParanthesis(s, open - 1, close);
        s.pop_back();
    }
    if(close > 0 && open < close) {
        s.push_back(')');
        generateParanthesis(s, open, close - 1);
        s.pop_back();

    }
}

int main() {
    int n; cin >> n;
    string s = "";
    generateParanthesis(s, n, n);

    return 0;
}