#include<bits/stdc++.h>
#define ll long long int
#define vi vector< int >
#define rep(i,a,b) for (int i = a; i < b; ++i)

using namespace std;



int main() {
	int t; cin>>t;
	while(t--) {
		int n; cin >> n;
		vi a(n + 1, 0);
		bool flag = false;
		int prev = 0;
		rep(i, 1, n + 1) {
			int data;
			cin >> data;
			if(data < prev) {
				flag = true;
			}
			prev = data;
			a[data]++;
		}
		if(flag) {
			rep(i, 1, n + 1) {
				if(a[i] == 0) {
					flag = false;
					break;
				}
			}
		}
		
		if(flag) {
			cout << "yes" << endl;
		}else {
			cout << "no" << endl;
		}
	}
	return 0;

}
