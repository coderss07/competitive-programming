// Author : Sarthak Sharma
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
#define N 1e6
#define mod 1000000007
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

// <------------------------------------- Code ------------------------------------->

int RainwaterTraping(vector<int> a, int n) {
	int left_max[n];
	int right_max[n];
	int m = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] >= m) {
			m = a[i];
		}
		left_max[i] = m;
	}
	
	m = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] >= m){
			m = a[i];
		}
		right_max[i] = m;
	}
	
	int total=0;
	for (int i = 0; i < n; ++i)
	{
		int lev = min(left_max[i], right_max[i]);
		total += (lev - a[i]);
	}
	return total;
}

int main() {
	clock_t begin_69 = clock();
	fast_io;
	int t; cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cout << RainwaterTraping(a, n) << endl;
	}

	return 0;
}

