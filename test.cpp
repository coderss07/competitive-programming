#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		int a[n+1];
		int h[101]={0};
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int k=x*y;
		int tot=0;
		for(int i=1; i<=n; i++){
			int j=a[i];
			while(j>0 && j>=a[i]-k){
				h[j]=1;
			}
			j=a[i];
			while(i<=100 && i<=a[i]+k){
				h[i]=1;
			}
		}
		for(int i=1; i<=n; i++){
			if(a[i]==0)
				tot++;
		}
		cout<<tot<<endl;
		
	}
	
	return 0;
}