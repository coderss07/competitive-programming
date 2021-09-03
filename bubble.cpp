#include <bits/stdc++.h>
// #include<iostream.h>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubble(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n - i; j++) {
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}

int main() {
	int a[] = {12, 34, 78, 2, 45, 99, 1, 789};
	int n = 8;
	bubble(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
