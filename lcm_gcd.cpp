#include <bits/stdc++.h>
// #define mod 1e9+7

using namespace std;

// Euclied's Formula  0648006091084804032022111923

const int mod = 1e9 + 7;

int hcf[1000][1000];
int gcd(int a, int b) {
	if(b == 0) return a;
	if(hcf[a][b] != -1) return hcf[a][b];
	return hcf[a][b] = gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int rec_pow(int a, int b) { // recursive
	if(b == 0) return 1;
	int res = rec_pow(a, b >> 1);
	if(b & 1) return (a * ((res * 1LL * res) % mod)) % mod;
	else return (res * 1LL * res) % mod;
}

int binMul(int a, int b) {
	int ans = 0;
	while(b) {
		if(b & 1) {
			ans = (ans % mod + a % mod) % mod;
		}
		a = (a % mod + a % mod) % mod;
		b >>= 1;
	}
	return ans;
}

int iter_pow(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) {
			ans = binMul(ans, a);
		}
		a = binMul(a, a);
		b >>= 1;
	}
	return ans;
}

long long it_pow(long long a, long long b) {
	long long ans = 1;
	while(b) {
		if(b & 1) {
			ans = ans * a;
		}
		a = a * a;
		b >>= 1;
	}
	return ans;
}

// to check divisor of no in sqrt(n) complexity
void divisor(int n) {
	int sum(0), cnt(0);
	for(int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			sum += i, cnt++;
			if(n / i != i) sum += n / i, cnt++;
		}
	}
	cout << "Sum = " << sum << endl;
	cout << "Count = " << cnt << endl;
}

vector<int> prime_factorization(int n) {
	vector<int> ans;
	for(int i = 2; i * i <= n; i++) {
		while(n % i == 0) {
			ans.push_back(i);
			n /= i;
		}
	}
	if(n > 1) ans.push_back(n);
	return ans;
}

// vector<int> prime_factorization2(int n) {
// 	vector<int> ans;
// 	while(n > 1) {
// 		int pf = highest_prime[n];
// 		while(!(n % pf)) {
// 			ans.push_back(pf);
// 			n /= pf;
// 		}
// 	}
// 	return ans;
// }

int main() {
	// memset(hcf, -1, sizeof hcf);
	// cout << gcd(12, 18) << endl;
	// cout << lcm(12, 18) << endl;
	// cout << _pow(2, 4) << endl;
	// cout << iter_pow(2, 4) << endl;
	// divisor(36);
	// for(int e: prime_factorization(100)) cout << e << " ";
	// cout << endl;
	cout << (int)log2(5);
	// vector<int> a = {34, 67, 89, 67, 34, 34, 98, 33, 18, 90, 56, 11, 34, 33};
	// sort(a.begin(), a.end());
	// for(auto e: a) cout << e << " ";

	// Multiplicative inverse of n is BinExp of n & mod - 2 ie. bin_pow(n, mod - 2); 
	return 0;
}