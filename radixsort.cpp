#include <bits/stdc++.h>

using namespace std;

int max(int a[], int n) {
	int m = a[0];
	for (int i = 1; i < n; ++i) {
		m = max(m, a[i]);
	}
	return m;
}

void countsort(int a[], int n, int p) {
	int count[10] = {0};
	int *b = new int[n];
	for (int i = 0; i < n; i++)
		count[(a[i] / p) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];

	for (int i = n - 1; i >= 0; i--)
		b[--count[(a[i] / p) % 10]] = a[i];

	for (int i = 0; i < n; ++i)
		a[i] = b[i];
	delete b;
}

void radix_sort(int a[], int n) {
	int m = max(a, n);
	int pos = 1;

	while (m / pos > 0) {
		countsort(a, n, pos);
		pos *= 10;
	}
}

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	radix_sort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
