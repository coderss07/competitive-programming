#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const int N = 1e3;
vector<int> cat(N, -1);

int catalan(int n){
	if(n <= 1){
		return 1;
	}
	if(cat[n] != -1) { return cat[n]; }
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += catalan(i) * catalan(n - 1 - i);
	}
	return cat[n] = ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n; 
		cin >> n;
		cout << catalan(n) << endl;
	}
	return 0;
}
