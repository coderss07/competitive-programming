#include<bits/stdc++.h>

using namespace std;

int maxNonrepeating(string s){
	int j = -1, ans = 0;
	int ind[26];
	for (int i = 0; i < 26; ++i)
	{
		ind[i] = -1;
	}
	for (int i = 0; i < s.size(); ++i){
		if(ind[s[i] - 'a'] != -1){
			j = ind[s[i] - 'a'];
		}
		ind[s[i] - 'a'] = i;		
		ans = max(ans, i - j);
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int ans = maxNonrepeating(s);
		cout << ans << endl;
	}
	return 0;
}