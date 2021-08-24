#include <iostream>
#include <conio.h>

using namespace std;

bool get_bit(int n, int pos) {
	return (n & (1<<pos))!=0;
}

int set_bit(int n, int pos) {
	return (n | (1<<pos));
}

int clear_bit(int n, int pos) {
	return (n & ~(1<<pos));
}

bool power_0f2(int n) {
	return (n && !(n & n-1));
}

int no_of1s(int n) {
	int cnt=0;
	while(n) {
		n = (n & n-1);
		cnt ++;
	}
	return cnt;
}

int unique(int *a, int n) {
	int xorsum = 0;
	for(int i=0; i<n; i++){
		xorsum = xorsum ^ a[i];
	}
	return xorsum;
}

void subset(int  *a, int n) {
	for(int i = 0; i < (1<<n); i++) {
		cout<<"{ ";
		for(int j = 0; j < n; j++){
			if(i & (1<<j))
				cout<< a[j] <<" ";
			else
				cout<< "- ";
		}cout<<" }"<<endl;
	}
}

int main() {

	// cout<< get_bit(10, 2) << endl;
	// cout<< set_bit(8, 2) << endl;
	// cout<< clear_bit(12, 2) << endl;

	// int n = 1025;
	// cout<< (power_0f2(n) ? "Yes" : "No") << endl;

	// cout<< no_of1s(60) << endl;

	// int a[3] = {1,2,3};
	// subset(a, 3);

	int a[6] = {1, 2, 3, 2, 1, 3};
	cout<< unique(a, 6) << endl;

	return 0;
}