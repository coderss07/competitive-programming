#include<bits/stdc++.h>

using namespace std;

int RainwaterTraping(vector<int> a, int n) {
	int left_max[n];
	int right_max[n];
	int m = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] >= m) {
			left_max[i] = a[i];
		}else {
			left_max[i] = m;
		}
		m = max(m, a[i]);
	}
	
	m = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] >= m){
			right_max[i] = a[i];
		}else{
			right_max[i] = m;
		}
		m = max(m, a[i]);
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
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		
		cout << RainwaterTraping(a, n) << "\n";
	}
	
	return 0;
}
