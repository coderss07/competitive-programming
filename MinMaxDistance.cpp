#include<bits/stdc++.h> 

using namespace std;

bool isSatisfying(int *a, int n, int m, int k) {

	int pos = a[0];
	int cnt=1;
	for (int i = 1; i < n; ++i) {
		if(a[i] - pos >= m) {
			pos = a[i];
			cnt ++;
		}
		if(cnt == k) {
			return true;
		}
	}
	return false;

}

int largestMinDistance(int *a, int n, int k){
	sort(a,a+n);
	int res = 0;
	int l = 1;
	int r = a[n-1];

	while(l < r) {
		int mid = (l+r)/2;
		if(isSatisfying(a, n, mid, k)) {
			res = max(res, mid);
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return res;

}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,k; 
		cin>>n>>k;
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		cout<< largestMinDistance(a,n,k) <<endl;
	}
	return 0;
}
