#include<bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		rep(i, 0, n) {
			cin >> a[i];
		}
		sort(a.begin(), a.end(), greater<int>());
		int ans = 0;
		rep(i, 0, n) {
			ans += x / a[i];
			x = x % a[i];
		}
		
		cout << ans << endl;
	}
	return 0;

}
