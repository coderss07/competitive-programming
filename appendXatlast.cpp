/*
You are give a string and you have to append the 'x' at last of the string and print.

INPUT:

First line will contain T, number of testcases. Then the testcases follow.
The first line of each test case contain a string.

OUTPUT:

For each testcase, output the String.

SAMPLE INPUT:

2
acxxcixytgytxjhxxjhuyt
axaxaxaxaxaxgfhgfhygfhhiuytxxxxxx

SAMPLE OUTPUT:

acciytgytjhjhuytxxxxxx
aaaaaagfhgfhygfhhiuytxxxxxxxxxxxx

CONSTRAINTS:

1 <= T <= 10^3
1 <= |s| <= 10^4


*/
#include<bits/stdc++.h>

using namespace std;

string appendAtLast(string s){
	if(s.size() == 0){
		return "";
	}

	string valid = appendAtLast(s.substr(1));

	if(s[0] == 'x')
		return (valid + s[0]);
	return (s[0] + valid);
}

int main() {
	int t; cin >> t;
	while(t--) {
		string s;
		cin >> s;

		cout << appendAtLast(s) << endl;
	}
	return 0;
}
