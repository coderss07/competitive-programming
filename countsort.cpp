#include <bits/stdc++.h>

using namespace std;

//It works only for the array having positive integers

int max(int a[], int n) {
	int m = a[0];
	for (int i = 1; i < n; ++i) {
		m = max(m, a[i]);
	}
	return m;
}

void countsort(int a[], int n) {
	int m = max(a, n);
	int count[m + 1] = {0};
	int b[n];
	for (int i = 0; i < n; i++)
		count[a[i]]++;
	for (int i = 1; i <= m; i++)
		count[i] = count[i] + count[i - 1];
	for (int i = n - 1; i >= 0; i--)
		b[--count[a[i]]] = a[i];
	for (int i = 0; i < n; ++i)
		a[i] = b[i];
}

int main() {
	int a[] = {12, 34, 78, 2, 45, 99, 0, 1, 789};
	int n = 9;
	countsort(a, n);
	// cout<<max(a,n)<<endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
