#include<bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int> &a, int n){
	stack< pair<int, int> > st;
	vector<int> ans;
	ans.push_back(1);
	st.push({a[0], 1});
	for (int i = 1; i < n; ++i){
		int cnt = 1;
		while(!st.empty() && a[i] >= st.top().first) {
			cnt += st.top().second;
			st.pop();
		}
		ans.push_back(cnt);
		st.push({a[i], cnt});
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i: a){
			cin >> i;
		}
		vector<int> ans;
		ans = stockSpan(a, n);
		for(auto &i: ans){
			cout << i << " ";
		}cout << endl;
	}
	return 0;
}
