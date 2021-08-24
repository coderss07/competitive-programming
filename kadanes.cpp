#include <bits/stdc++.h>

using namespace  std;

int kadenes(int *a, int n){
	int maxSum=INT_MIN;
	int curr=0;
	for (int i = 0; i < n; ++i)
	{
		curr = curr + a[i];
		if(curr < 0)
			curr=0;
		maxSum = max(maxSum, curr);
	}
	return maxSum;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	int nonwrapSum=kadenes(a,n);
	int wrapSum=0;
	int total=0;
	for (int i = 0; i < n; ++i)
	{
		total+=a[i];
		a[i]=-a[i];
	}
	wrapSum = total + kadenes(a,n);

	
	cout<< max(wrapSum,nonwrapSum) <<endl;
	return 0;
}