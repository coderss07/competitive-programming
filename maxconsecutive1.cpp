#include<bits/stdc++.h>

using namespace std;

/* Maximum consecutive one's in an array in which k 0's can revert to 1's
2
12 2
1 1 0 1 1 0 1 0 0 0 0 1
7 3
0 0 0 0 0 1 1

*/

int maxConsecutiveones(vector<int> a, int n, int k){
	int j=0,cnt_zeros=0,ans=0;
	for (int i = 0; i < n; ++i){
		if(a[i] == 0)
			cnt_zeros++;
		while(cnt_zeros > k){
			if(a[j] == 0){
				cnt_zeros--;
			}
			j++;
		}
		ans = max( ans, i-j+1);
	}
	return ans;

}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		vector<int> a(n);
		for (auto &i: a){
			cin>>i;
		}
		
		int ans=maxConsecutiveones(a,n,k);
		cout<< ans <<endl;
	}
	return 0;
}
