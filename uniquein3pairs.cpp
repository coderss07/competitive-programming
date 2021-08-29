#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int getBit(int n,int pos){
	return (n & (1<<pos)) != 0;
}

ll setBit(int n,int pos){
	return (n | (1<<pos));
}

int unique(int *a, int n){
	int uni=0;
	for (int i = 0; i < 64; i++)
	{
		int cnt=0;
		for(int j=0; j<n; j++){
			if(getBit(a[j],i) != 0){
				cnt++;
			}
		}
		if(cnt%3 != 0){
			uni = setBit(uni, i);
		}
	}
	return uni;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<unique(a,n)<<endl;
	return 0;

}