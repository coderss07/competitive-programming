#include<bits/stdc++.h>

using namespace std;

void sub_sum(int a[], int n, int sum = 0) {
	if(n == 0) {
		if(sum != 0)
			cout << sum << " ";
		return;
	}
	sub_sum(a + 1, n - 1, sum);
	sub_sum(a + 1, n - 1, sum + a[0]);
}

int main() {
	int a[] = {1, 2};
	sub_sum(a, 2);
	return 0;
}
