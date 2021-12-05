#include <bits/stdc++.h>

using namespace std;

bool get_bit(int n, int pos) {
	return (n & (1<<pos)) != 0;
}

int set_bit(int n, int pos) {
	return (n | (1<<pos));
}

int clear_bit(int n, int pos) {
	return (n & ~(1<<pos));
}

bool power_Of2(int n) {
	return (n && !(n & n-1));
}

bool power_Of4(int n) {
	return (n && !(n & n-1) && !(n & 0b101010101010101010101010101010101010));
}

bool power_Of3(int n) {
	return (n > 0 && (1162261467 % n == 0));
}

uint32_t reverseBits(uint32_t n) {
	uint32_t ans = 0;
	for(int i = 0; i < 32; i++) {
		ans <<= 1;
		if(n & 1) ans++;
		n >>= 1;
	}
	return ans;
}

uint32_t duplicate(int *a, int n) {
	int ans = 0;
	for(int k = 0; k < 32; k++) {
		int x = 0, y = 0;
		for(int i = 0; i < n; i++) {
			if(get_bit(i, k)) x++;
			if(get_bit(a[i], k)) y++;
		}
		if(x < y) ans = (ans << k);
	}
	return ans;
}

int no_of1s(int n) {
	int cnt=0;
	while(n) {
		n = (n & n - 1);
		cnt++;
	}
	return cnt;
}

int unique(int *a, int n) {
	int xorsum = 0;
	for(int i = 0; i < n; i++){
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
		}cout<<"}"<<endl;
	}
}

int main() {

	// cout<< get_bit(10, 2) << endl;
	// cout<< set_bit(8, 2) << endl;
	// cout<< clear_bit(12, 2) << endl;

	// int n = 1025;
	// cout<< (power_Of2(n) ? "Yes" : "No") << endl;
	// cout<< (power_Of4(8) ? "Yes" : "No") << endl;
	// cout<< (power_Of3(27) ? "Yes" : "No") << endl;
	// cout << reverseBits(1) << endl;

	// cout<< no_of1s(60) << endl;

	int a[3] = {1,2,3};
	subset(a, 3);

	// int a[7] = {4, 1, 2, 3, 2, 1, 3};
	// cout<< unique(a, 7) << endl;
	// const int sz = 1e4 + 1;
    // string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    // string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    // int n1 = stoi(a, 0, 2);
    // int n2 = stoi(b, 0, 2);
    // string s = bitset<sz>(n1 + n2).to_string();
    // int i;
    // for(i = 0; i < s.size(); i++) {
    // 	if(s[i] == '1') {
    // 		break;
    // 	}
    // }
    // s = s.substr(i);
    // if(s.empty()) {
    // 	s += "0";
    // }
    // cout << bitset<20>(21) << endl;
    // cout << 0b1110001;

	return 0;
}