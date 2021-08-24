#include<bits/stdc++.h>

using namespace std;

string rev(string s){
	string r="";
	int i=s.size()-1;
	int j;
	while(i>=0){
		while(i>=0 && s[i]==' ') i--;
		j=i;
		if(i<0) break;
		while(i>=0 && s[i]!=' ')i--;
		if(r!="")
			r+=" ";
		r+=s.substr(i+1,j-i);
	}
	return r;
}

int main() {
	string s="   hello   my name   is sarthak  sharma    ";
	// fflush(stdin);
	// cin>>s;
	string r=rev(s);
	cout<<r<<endl;
	return 0;
}