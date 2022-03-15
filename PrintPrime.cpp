#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void printPrime(int n){
	bool NotPrime[n+1];
	for(int i=2; i * i <= n; i++){
		for(int j=i*i; j<=n; j+=i){
			NotPrime[j]=true;
		}
		if(i*i>n)
			break;
	}
	for (int i = 2; i <= n; ++i)
	{
		if(NotPrime[i] == false)
			cout<<i<<" ";
	}

}

int main() {
	int n;
	cin>>n;
	printPrime(n);
	
	return 0;

}
