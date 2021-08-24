#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const int N = 1e6 + 10;
const int INF = 1e6 + 10;
vector<ll> dp(N, INF);

ll min_square(ll n) {
    if(n <= 3) {
        return n;
    }
    if(dp[n] == INF) {
        for(int i = 1; i * i <= n; i++) {
            dp[n] = min(dp[n],1 + min_square(n - i*i));
        }
    }
    return dp[n];
}

int main() {
	int t;
	cin>>t;
	while(t--) { 
		ll n; cin>>n;
		
		cout<< min_square(n) <<endl;
	}
	return 0;
}
