#include<bits/stdc++.h>

using namespace std;

void heapify(int a[],int n,int i) {

	int lar = i;
	int lc = (2*i) + 1;
	int rc = (2*i) + 2;
	if(lc<n && a[lc] < a[lar])
		lar = lc;
	if(rc<n && a[rc] < a[lar])
		lar = rc;
	if(lar != i){
		swap(a[i],a[lar]);
		heapify(a,n,lar);
	}
	
}

void heapSort(int a[], int n){
	//for creating min heap
	for(int i=(n/2)-1; i>=0; i--){
		heapify(a,n,i);
	}

}

int main(){
	int a[]={12, -3, 78, 2, 45, 99, -1, 989};
	int n=8;
	heapSort(a,n);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}