#include <bits/stdc++.h>

using namespace  std;
int main() {
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	int maxSum=INT_MIN;
	int curr=0;
	for (int i = 0; i < n; ++i)
	{
		curr = curr + a[i];
		if(curr < 0)
			curr=0;
		maxSum = max(maxSum, curr);
	}
	cout<< maxSum <<endl;
}