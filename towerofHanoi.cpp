#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void tower_of_hanoi(int n, char sc, char des, char help){
	if(n==0){
		return;
	}
	tower_of_hanoi(n - 1, sc, help, des);
	cout << "Move block from " << sc << " to " << des << endl;
	tower_of_hanoi(n - 1, help, des, sc);
}

int main() {
	tower_of_hanoi(3, 'S', 'D', 'H');
	return 0;
}
