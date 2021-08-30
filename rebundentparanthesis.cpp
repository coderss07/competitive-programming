#include<bits/stdc++.h>

using namespace std;

bool rebundent_paranthesis(string s){

	stack<char> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] != ')'){
			st.push(s[i]);
		}else{
			if(st.top() == '(')
				return true;
			while(!st.empty() && st.top() != '('){
				st.pop();
			}
			st.pop();
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		if(rebundent_paranthesis(s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
