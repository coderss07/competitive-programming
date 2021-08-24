#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N = 100001;
vector<int> mp(N, 0);

int main()
{
	ll m, n;
	cin >> m >> n;
	// memset(mp, sizeof(mp), 0);
	
	for(ll i = 0; i < m; i++)
	{
		ll k, x;
		cin >> k >> x;
		mp[x]++;
	}
	ll cnt = 0;
	for(ll i = 0; i < n; i++)
	{
		ll l;
		cin >> l;
		
		if(mp[l]) cnt++;
	}
	
	if(cnt == n)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	
	return 0;
}
