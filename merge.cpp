#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

void merge(int a[], int l, int m, int h) {
	int i = l;
	int j = m + 1;
	int k = 0;
	int* b = new int[h - l + 1];
	while (i <= m && j <= h) {
		if (a[i] < a[j]) {
			b[k] = a[i];
			i++;
		}else {
			b[k] = a[j];
			j++;
		}
		k++;
	}

	while (i <= m) {
		b[k] = a[i];
		i++;
		k++;
	}

	while (j <= h) {
		b[k] = a[j];
		j++;
		k++;
	}
	
	for (i = l; i <= h; i++)
		a[i] = b[i - l];
	
	delete b;
}

void mergeSort(int a[], int l, int h) {

	if (l < h) {
		int mid = (l + h) / 2;

		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, h);
		
		merge(a, l, mid, h);
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		mergeSort(a, 0, n - 1);

		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}cout << endl;
	}

	return 0;
}