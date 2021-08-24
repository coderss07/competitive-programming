#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int catalan(int n){
	if(n<=1){
		return 1;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += catalan(i)*catalan(n-1-i);
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n; 
		cin>>n;
		cout<< catalan(n) <<endl;
	}
	return 0;
}
