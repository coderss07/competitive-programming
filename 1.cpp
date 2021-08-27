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
		vi a(n);
		rep(i, 0, n) {
			cin >> a[i];
		}

		int ans = 0;
		rep(i, 1, n) {
			int temp = abs(a[i] - a[i - 1]) - 1;
			ans += temp;
		}
		
		cout << ans << endl;
		
	}
	return 0;

}
