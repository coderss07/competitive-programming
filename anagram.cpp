#include<bits/stdc++.h>

using namespace  std;

bool isAna(string s1, string s2){
	if(s1.size() != s2.size())
		return false;
	// lower(s1);
	int hsh[26] = {0};
	for(int i = 0; i < s1.size(); i++){
		hsh[s1[i] - 'a']++;
		hsh[s2[i] - 'a']--;
	}
	for(int i = 0; i < 26; i++){
		if(hsh[i] != 0 )
			return false;
	}
	return true;
}

int main(){
	string s1 = "ramga";
	string s2 = "grama";
	cout << (isAna(s1, s2) ? "Yes" : "NO") << endl;
	return 0;
}