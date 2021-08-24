#include<bits/stdc++.h>

using namespace std;

unordered_map<char, int> bracket{{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};

bool balanced(string s){
	stack<char> st;
	for (int i = 0; i < s.size(); i++){
		if(bracket[s[i]] < 0){
			st.push(s[i]);
		}else if(bracket[s[i]] > 0){
			if(st.empty() || (bracket[s[i]] + bracket[st.top()]) != 0){
				return false;
			}else{
				st.pop();
			}
		}
	}
	if(!st.empty()){
		return false;
	}


	return true;

}

int main() {
	string s = "[{(()})(())]";
	cout<< (balanced(s)? "Balanced" : "Unbalanced") <<endl;
	
	return 0;
}
