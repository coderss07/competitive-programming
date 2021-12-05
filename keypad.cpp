#include<bits/stdc++.h>

using namespace std;

string keys[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void substrings(string s,string ans = ""){
	if(s.size()==0){
		cout<<"{ " << ans << " }" <<endl;
		return;
	}
	string code=keys[s[0] - '0'];
	for (int i = 0; i < code.size(); ++i){
		substrings(s.substr(1),ans+code[i]);
	}
}

int main() {
	substrings("792");
	return 0;
}
