#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int subarray_divby3(vector<int> a, int n, int k) {

	int sum = 0;
	for(int i=0; i<n; i++){
		sum += a[i];
	}
	if(sum % 3 == 0){
		return 0;
	}
	for (int i = k; i < n; ++i){
		sum += a[i];
		sum -= a[i - k];
		if(sum % 3 == 0){
			return i-k + 1;
		}
	}
	return -1;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,k; 
		cin>>n>>k;
		vector<int> a;
		for (int i = 0; i < n; ++i){
			int item;
			cin>>item;
			a.push_back(item);
		}
		int in = subarray_divby3(a, n, k);
		if(in != -1){
			for(int i=in; i < k + in; i++){
				cout<<a[i];
			}cout<<endl;
		}
	}
	
	return 0;
}
