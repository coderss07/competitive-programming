#include<bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;

const int N = 1e5 + 10;
vector<int> dp(N, -1);

int fibo(int n) {
    if(n == 0 || n == 1) return 0;
    if(n == 2) return 1;
	
	if(dp[n] == -1) {
        dp[n] = fibo(n - 1) + fibo(n - 2);
    }
    return dp[n];
}

// int fibo(int n) {
    // if(n == 0 || n == 1) return 0;
    // if(n == 2) return 1;                 // TIME LIMIT EXCEEDED ...

//     return fibo(n-1) + fibo(n-2);
// }

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << fibo(n) << endl;
	}
	return 0;

}
