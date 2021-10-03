#include<bits/stdc++.h>

using namespace std;

string proper(string s){
	string r = "";
	int i = 0;
	int j;
	while(i < s.size()) {
		while(i < s.size() && s[i] == ' ') i++;
		j = i;
		if(i >= s.size()) break;
		
		while(i < s.size() && s[i] != ' ') i++;
		if(r != "")
			r += " ";
		r += s.substr(j, i - j);
	}
	return r;
}

int main() {
	string s;
	s = "   hello      my name   is sarthak  sharma    ";
	s = proper(s);
	cout << s << endl;
	return 0;
}