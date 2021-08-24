#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;

const int INF = 11;

int main() {
	int t; cin>>t;
	while(t--) {
		int n;
		cin >> n;
		unordered_map<string, pair<int, int> > mp;
		rep(i, 0, n) {
			string s;
			bool sp;
			cin >> s >> sp;
			if(!sp) {
				mp[s].first++;
			}else {
				mp[s].second++;
			}
		}
		int ans = 0;
		for(auto &it: mp) {
			ans += max(it.second.first, it.second.second);
		}
		
		cout << ans << endl;
		
	}
	return 0;

}
