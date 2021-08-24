#include<bits/stdc++.h>
#define ll long long int
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;

/*
Given an ARRAY 'a' of 'n' elements. We have to remove
exactly 'n/2' elements from 'a' and add to array(initially empty)
'b'.

find max and min diff between 'a' and 'b'.

sigma(abs(a[i] - b[i]))

eg:4				for max:
12 -3 10 0			a: -3 0   b: 12 10
					ans: (abs(12 - (-3)) + abs(10 - 0)) = 25
ans = 5 25;			for max:
					a: -3 12   b: 0 10
					ans: (abs(0 - (-3)) + abs(10 - 12)) = 5
*/

int main() {
	int t;
	cin>> t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,0,n) {
			cin>> a[i];
		}
		sort(a.begin(),a.end());
		ll max_diff = 0;
		ll min_diff = 0;
		rep(i,0,n) {
			if(i<n/2) {
				max_diff -= a[i];
			}else{
				max_diff += a[i];
			}

			if(i%2 == 0) {
				min_diff -= a[i];
			}else{
				min_diff += a[i];
			}
		}
		
		cout<< min_diff << " " << max_diff << endl;
	}
	return 0;

}
