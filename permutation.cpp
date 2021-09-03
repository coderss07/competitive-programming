#include<bits/stdc++.h>

using namespace std;

void permutation(string s, string sol = ""){
	if(s.length() == 0){
		cout << sol << endl;
		return;
	}
	for(int i = 0; i < s.length(); i++){
		permutation(s.substr(0, i) + s.substr(i + 1), sol + s[i]);
	}
}

int main() {
	permutation("ABC"); 
	return 0;
}
