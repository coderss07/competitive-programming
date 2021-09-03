#include<bits/stdc++.h>
#define pii pair<int,int>
#define rep(i,a,b) for (int i = a; i < b; ++i)


/*
3
4
1 4 7 10
3
2 6 7
4
3 5 9 12
*/
using namespace std;

int main() {
	int k;
	cin >> k;
	vector<vector<int>> a(k);
	rep(i, 0, k) {     //i = 0 to i<n & i++
		int n;
		cin >> n;
		a[i] = vector<int>(n);
		rep(j, 0, n) {
			cin >> a[i][j];
		}
	}
	vector<int> idx(k, 0);

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	rep(i, 0, k) {
		pq.push({a[i][0], i});
	}
	
	vector<int> ans;
	while(!pq.empty()) {
		pii p = pq.top();
		pq.pop();

		ans.push_back(p.first);

		if(idx[p.second] + 1 < a[p.second].size()) {
			pq.push({a[p.second][idx[p.second] + 1], p.second});
		}
		idx[p.second]++;
	}
	for(auto &it: ans) {
		cout << it << " ";
	} cout << endl;
	return 0;

}
