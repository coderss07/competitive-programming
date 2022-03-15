#include <bits/stdc++.h>

using namespace  std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int maxSum = 0;
	int curr = 0;
	for (int i = 0; i < n; ++i)
	{
		curr = curr + a[i];
		maxSum = max(maxSum, curr);
		if(curr < 0)
			curr = 0;
	}
	cout << maxSum << endl;
}