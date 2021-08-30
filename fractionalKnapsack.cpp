#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;

int main() {
	int n, w;
	cin >> n >> w;
	vector<pii> a(n);
	rep(i, 0, n) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), [&](pii &a, pii &b){
		return (float)a.first / a.second > (float)b.first / b.second;
	});
	float ans = 0;
	rep(i, 0, n) {
		if(w >= a[i].second) {
			ans += a[i].first;
			w -= a[i].second;
		}else {
			float vpw = (float)a[i].first / a[i].second;
			ans += vpw * w;
			w = 0;
			break;
		}
	}
	cout << ans << endl;
	return 0;

}
