#include<bits/stdc++.h>

using namespace std;

// int f_occ(int a[], int n, int i, int k){
// 	if(i==n)
// 		return -1;
// 	if(a[i] == k){
// 		return i;
// 	}
// 	return f_occ(a,n,i+1,k);
// }

// int l_occ(int a[], int n, int i, int k){
// 	if(i==n)
// 		return -1;
// 	int l_o=l_occ(a,n,i+1,k);
// 	if(l_o == -1){
// 		if(a[i] == k){
// 			return i;
// 		}
// 	}
// 	return l_o;
// }

void reverse(int a[], int n){
	if(n==0)
		return;
	reverse(a+1,n-1);
	cout<<a[0]<<" ";
}

void reverse_str(string s){
	if(s.length() == 0){
		cout<<endl;
		return;
	}
	string r = s.substr(1);
	reverse_str(r);
	cout<<s[0];
}

int main() {
	int n,k;
	cin>>n>>k;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	reverse(a,n);
	reverse_str("hello");
	return 0;
}