#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int Min_sizeSubarray(vector<int> a, int n, int x) {

	int i=-1, j=0;
	int ans = INT_MAX;
	int sum = 0;
	while(i<n && j<n) {
		if(sum > x) {
			i++;
			sum -= a[i];
			ans = min(ans, j - i);
		}else{
			sum += a[j];
			j++;
		}
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,x; 
		cin>>n>>x;
		vector<int> a;
		for (int i = 0; i < n; ++i){
			int item;
			cin>>item;
			a.push_back(item);
		}
		cout<< Min_sizeSubarray(a, n, x) << "\n";
	}
	
	return 0;
}
