#include<bits/stdc++.h>

using namespace std;

int max(int a[], int n) {
	int m=a[0];
	for (int i = 1; i < n; ++i){
		if(a[i]>m)
			m=a[i];
	}
	return m;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int m=max(a,n);
	int w[m][n]={{0}};
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			w[j][i]=1;
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(w[i][j]==0)
				w[i][j]=2;
			else break;
		}
		for(int j=n-1;j>=0;j--){
			if(w[i][j]==0)
				w[i][j]=2;
			else break;
		}
	}
	int cnt=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(w[i][j]==0)
				cnt++;
		}

	}
	cout<<cnt<<"\n";
	
	
	
	return 0;
}