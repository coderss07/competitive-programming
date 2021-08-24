#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n,k; 
		cin>>n>>k;
		vector<ll> a;
		for (int i = 0; i < n; ++i){
			ll item;
			cin>>item;
			a.push_back(item);
		}
		deque<ll> dq;
		vector<int> ans;
		for (int i = 0; i < k; ++i){
			while(!dq.empty() && a[i] >= a[dq.back()]){
				dq.pop_back();
			}
			dq.push_back(i);
		}
		ans.push_back(a[dq.front()]);
		for(int i=k; i<n; i++){
			while(!dq.empty() && dq.front() <= i-k){
				dq.pop_front();
			}
			while(!dq.empty() && a[i] >= a[dq.back()]){
				dq.pop_back();
			}
			dq.push_back(i);
			ans.push_back(a[dq.front()]);
		}
		for(auto &i: ans){
			cout<<i<< " ";
		}
	}
	
	return 0;
}
