#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
    string ans = "";
    for(int g = 0; g < s.size(); g++) {
        int j = g;
        for(int i = 0; j < s.size(); i++, j++) {
            if(g == 0) {
                dp[i][j] = true;
            }else if(g == 1) {
                if(s[i] == s[j]) {
                    dp[i][j] = true;
                }
            }else {
                if(s[i] == s[j] && dp[i + 1][j - 1] == true) {
                    dp[i][j] = true;
                }
            }
            if(dp[i][j]) {
                ans = s.substr(i, j - i + 1);
            }
        }

    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		string ans = longestPalindrome(s);
		cout << ans << endl;
	}
	return 0;
}