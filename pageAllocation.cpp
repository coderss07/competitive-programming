#include<bits/stdc++.h> 

using namespace std;

bool isSatisfying(int *a, int n, int mid, int m) {
	int st = 1, sum = 0;
	
	for (int i = 0; i < n; ++i) {
		if(a[i] >= mid) {
			return false;
		}
		if(a[i] + sum > mid){
			st++;
			sum = a[i];
			if(st > m) {
				return false;
			}
		}else{
			sum += a[i];
		}
		
	}
	return true;

}

int minimumAllocation(int *a, int n, int m){
	if(n < m) {
		return -1;
	}
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i) r += a[i];
		int res = INT_MAX;
	while(l < r) {
		int mid = (l + r) / 2;
		if(isSatisfying(a, n, mid, m)) {
			res = min(res, mid);
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}

	return res;

}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m; 
		cin >> n >> m;
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		cout << minimumAllocation(a, n, m) << endl;
	}
	return 0;
}
