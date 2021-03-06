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

void solve() {
	int n, k; 
	cin >> n >> k;
	vector<int> a(n); 
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	deque<int> dq;
	vector<int> ans;
	for(int i = 0; i < k; ++i) {
		while(!dq.empty() && a[i] >= a[dq.back()]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}
	ans.push_back(a[dq.front()]);
	for(int i = k; i < n; i++){
		while(!dq.empty() && dq.front() <= i - k) {
			dq.pop_front();
		}
		while(!dq.empty() && a[i] >= a[dq.back()]) {
			dq.pop_back();
		}
		dq.push_back(i);
		ans.push_back(a[dq.front()]);
	}

	for(auto &i: ans) {
		cout << i << " ";
	}cout << endl;
}

int main() {
	clock_t begin_69 = clock();
	fast_io;
	int t; cin >> t;
	while(t--)
		solve();

	return 0;
}

