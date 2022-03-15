#include<bits/stdc++.h>
#define ll long long int

using namespace std;

/*10
You are given an array of size n, Occurences of all unique elements in Array is 2,
except 2 elements whose occerences is only 1,
find the 2 distinct element whose occurence is 1.
1 2 3 1 4 3 7 2 7 8*/

int getBit(int n, int pos){
	return (n & (1 << pos)) != 0;
}

void unique(int *a, int n){
	int Xorsum = 0;
	for (int i = 0; i < n; ++i)
	{
		Xorsum = Xorsum ^ a[i];
	}
	int pos = -1;
	bool set = 0;
	while(!set){
		pos++;
		set = getBit(Xorsum, pos);
	}
	int Xor=0;
	for (int i = 0; i < n; ++i) {
		if(getBit(a[i], pos)) {
			Xor = Xor ^ a[i];
		}
	}
	cout << Xor << " " << (Xorsum ^ Xor) << endl;

}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	unique(a, n);
	return 0;

}
