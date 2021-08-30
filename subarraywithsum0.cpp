#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int prefix_sum = 0;
		map<int, int> m;
		rep(i, 0, n) {
			int data;
			cin >> data;
			prefix_sum += data;
			m[prefix_sum]++;
		}
		int ans = 0;
		for(auto &it: m) {

			int data = it.second;
			ans += (data * (data - 1)) / 2;

			if(it.first == 0) {
				ans += data;
			}

		}
		
		cout << ans << endl;
	}
	return 0;

}
