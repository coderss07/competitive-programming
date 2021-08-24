#include <bits/stdc++.h>

using namespace  std;

vector<int> NGF(vector<int> v){
	vector<int> ngf(v.size());
	stack<int> st;
	for(int i=0; i<v.size(); i++) {
		while(!st.empty() && v[i] > v[st.top()]) {
			ngf[st.top()]=v[i];
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		ngf[st.top()]=-1;
		st.pop();
	}
	return ngf;

}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; ++i) {
		cin>>v[i];
	}
	vector<int> ngf = NGF(v);
	for(int i=0; i<n; i++) {
		cout<<v[i]<<" "<<ngf[i]<<endl;
	}
	return 0;
}