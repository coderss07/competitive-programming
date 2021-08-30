#include<bits/stdc++.h>

using namespace std;

void substrings(string s, string ans = ""){
	if(s.size() == 0){
		cout << "{ " << ans << " }" << endl;
		return;
	}
	substrings(s.substr(1), ans);
	substrings(s.substr(1), ans + s[0]);
	// substrings(s.substr(1), ans + to_string(int(s[0])));

}

int main() {
	substrings("ABC");
	return 0;
}
