#include<bits/stdc++.h>
#define ll long long int
#define vs vector<string>
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;

int main() {
	int t; cin>>t;
	while(t--) {
		int n;
		cin >> n;
		vs st(n);
		rep(i, 0, n) {
			cin >> st[i];
		}
		vector<int> alpha(26, 0);
		for(auto &it: st) {
			rep(i, 0, it.size()) {
				if(it[i] == 'c' || it[i] == 'd' || it[i] == 'e' || it[i] == 'f' || it[i] == 'h' || it[i] == 'o')
					alpha[it[i] - 'a']++;
			}
		}

		alpha[2] /= 2;
		alpha[4] /= 2;
		int ans = INT_MAX;
		rep(i, 0, 26) {
			if(alpha[i] != 0) {
				ans = min(ans, alpha[i]);
			}
		}
		cout << ans << endl;
		
	}
	return 0;

}

