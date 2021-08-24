#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) { 
		int h, p;
		cin >> h >> p;
		int cp = 0;
		rep(i, 0, p) {
			if(p / pow(2, i) == 0) {
				break;
			}
			cp += p / pow(2, i);
		}
		
		if(cp >= h)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}
