#include <bits/stdc++.h>

using namespace  std;

void shellSort(int a[],int n){
	for(int gap=n/2;gap>=1;gap/=2) {
		for(int j=gap; j<n ;j++){
			for (int i = j-gap; i >= 0; i-=gap) {

				if(a[i+gap]>=a[i])
					break;
				else
					swap(a[i],a[i+gap]);
				
			}
		}
	}

}

int main() {
	int a[]={12, 34,78,2, 45, 99, 1, 89};
	int n=8;
	shellSort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}