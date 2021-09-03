#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int noOfOnes(int n){
	int cnt = 0;
	while(n != 0){
		n = (n & (n - 1));
		cnt++;
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	cout << noOfOnes(n) << endl;
	return 0;
}
