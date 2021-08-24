#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool is_perfect(int n) {
	int sum = 1;
	for(int i = 2; i * i <= n; i++) {
		if(n%i == 0) {
			if(i == n/i)
				sum += i;
			else
				sum += i + n/i;
		}
	}
	if(sum == n && n!=1)
		return true;
	return false;
}

int max_PerfectNum(vector<int> a, int k) {

	for(int i = 0; i < a.size(); i++) {
		if(is_perfect(a[i])) {
			a[i] = 1;
		}else{
			a[i] = 0;
		}
	}
	int sum = 0;
	
	for (int i = 0; i < k; ++i) {
		sum += a[i];
	}
	int m = sum;
	for (int i = k; i < a.size(); ++i){
		sum -= a[i-k];
		sum += a[i];
		m = max(m, sum);
	}
	
	return m;
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
		cout<< max_PerfectNum(a, k) <<endl;
	}
	 
	return 0;
}
