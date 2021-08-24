#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n,k,x; 
		cin>>n>>k>>x;
		vector<ll> a;
		for (int i = 0; i < n; ++i){
			ll item;
			cin>>item;
			a.push_back(item);
		}
		ll sum = 0;
		for (int i = 0; i < k; ++i){
			sum += a[i];
		}
		ll ans = 0;
		if(sum < x)
			ans = sum;
		for(int i=k; i<n; i++){
			sum -= a[i - k];
			sum += a[i];
			if(sum < x)
				ans = max(ans,sum);
		}
		cout<<ans<< "\n";
	}
	
	return 0;
}
