#include<bits/stdc++.h>

using namespace std;

string reverse(string s){
	stack<string> st;
	string r="";
	for (int i = 0; i < s.size(); i++){
		string temp="";
		while(s[i] != ' ' && i< s.size()){
			temp+=s[i];
			i++;
			// cout<<s[i]<<endl;
		}
		st.push(temp);
	}
	while(!st.empty()){
		string e=st.top();
		r+=e;
		st.pop();
		if(!st.empty()){
			r+=" ";
		}
	}

	return r;

}

int main() {
	string s="hello, how are you man!";
	cout<< reverse(s) <<endl;
	
	return 0;
}
