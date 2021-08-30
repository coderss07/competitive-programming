#include<bits/stdc++.h>
#define ll long long int
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		rep(i, 0, n) {
			cin >> a[i];
		}
		priority_queue<int, vector<int> > pq;
		rep(i, 0, n) {
			pq.push(a[i]);
		}
		int sum = 0;
		int cnt = 0;
		while(!pq.empty() && sum < k) {
			int data = pq.top();
			pq.pop();
			sum += data;
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;

}
