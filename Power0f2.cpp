#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool isPowerof2(int n){
	return (n && !(n & (n-1)));
}

int main() {
	int n;
	cin>>n;
	cout<<(isPowerof2(n) ? "Yes" : "No")<<endl;
	return 0;

}
