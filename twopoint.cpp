#include<bits/stdc++.h>

using namespace  std;
/*To find the triplets(a+b+c == 0) exist in  array*/

bool twoSum(int *a, int n, int s, int i) {
	int j = n - 1;
	while(i < j) {
		int sum = a[i] + a[j];
		if(sum == s){
			return true;
		}else if(sum < s) {
			i++;
		}else {
			j--;
		}
	}
	return false;
}

bool triplets(int *a, int n) {
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		int item = a[i];
		if(twoSum(a, n, -item, i + 1)) {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << (triplets(a, 5) ? "Yes" : "NO") << endl;
	return 0;
}