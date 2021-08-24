#include<bits/stdc++.h>

using namespace std;

void heapify(int a[], int i, int n) {

	int lar = i;
	int lc = (2*i) + 1;
	int rc = (2*i) + 2;
	
	if(lc < n && a[lc] > a[lar])
		lar = lc;

	if(rc < n && a[rc] > a[lar])
		lar = rc;

	if(lar != i){

		swap(a[i], a[lar]);
		heapify(a, lar, n);

	}
	
}

void heapSort(int a[], int n) {
	//for creating max heap

	for(int i = ( n/2 ) - 1; i >= 0; i--) {
		heapify(a, i, n);
	}

	// for sorting array
	for (int i = n - 1; i >= 1; i--) {
		swap(a[i], a[0]);
		heapify(a, 0, i);
	}

}

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	heapSort(a,n);
	
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}