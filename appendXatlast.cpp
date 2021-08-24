#include<bits/stdc++.h>

using namespace std;

string appendAtLast(string s){
	if(s.size()==0){
		return "";
	}
	string valid=appendAtLast(s.substr(1));
	if(s[0] == 'x')
		return (valid + s[0]);
	return (s[0] + valid);
}

int main() {
	cout<<appendAtLast("acxxcixytgytxjhxxjhuyt")<<endl;;
	return 0;
}
