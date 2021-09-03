#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include <set>
#include<unordered_set>
#include<bits/stdc++.h>

using namespace std;

int main() {
	// pair<int, string> p[5];
	// p.first = 4;
	// p.second = "Hello";
	// for(int i=0; i<5; i++) {
		// cin>>p[i].first;
		// cin>>p[i].second;
	// }
	// cout<<p.first<<" "<<p.second<<endl;
	// for (int i = 0; i < 5; ++i) {
	// 	cout<<p[i].first<<"-"<<p[i].second<<endl;
	// }

	// vector<int> v = {1, 2, 3, 4, 5, 6};
	// v.push_back(7);
	// v.pop_back();
	// v[2] = 8;   //update
	// for(auto &i: v) {
	// 	cout<<i<<" ";
	// }cout<<endl;

	// vector<int> :: iterator it;
	// it = v.begin();
	// cout<< *(++(++it)) <<endl;

	// vector<vector<int> > v;
	// for(int i=0; i<3; i++ ) {
	// 	vector<int> temp;
	// 	for(int j = 0; j<3; j++){
	// 		int val;
	// 		cin>>val;
	// 		temp.push_back(val);
	// 	}
	// 	v.push_back(temp);
	// }
	// for (int i = 0; i < 3; ++i)
	// {
	// 	for(int j=0; j<3; j++){
	// 		cout<< v[i][j] <<" ";
	// 	}cout<<endl;
	// }

	// map<int, string> lord;
	// lord[1] = "Lord_Shiva";
	// lord[2] = "Vishnu_Dev";
	// lord.insert({4,"Laxmi_mata"});
	// lord[3] = "Sai_Baba";
	
	// for(auto it: lord) {
	// 	cout<<it.first<<"->"<<it.second<<endl;
	// }

	// unordered_map<string, int> m;
	// for (int i = 0; i < 5; ++i) {
	// 	string s;
	// 	cin>>s;
	// 	m[s]++;
	// }
	// auto it = m.find("hello");
	// if(it!=m.end())
	// 	m.erase(it);
	// m.erase("hello");
	// m.clear();
	// for(auto it: m) {
	// 	cout<<it.first<<"->"<<it.second<<endl;
	// }

	// int ans = [](int x, int y = 0){return x*y;}(4,2);
	// cout<< ans <<endl;

	// int a[] = {-1, 2, 3, 4, 5};
	// bool is = all_of(a,a+5,[](int x){return x>0;});
	// cout<<is<<endl;

	// int a[] = {-1, -2, -3, 1, 5};
	// bool is = any_of(a,a+5,[](int x){return x==0;});
	// cout<<is<<endl;

	// int a[] = {1, 2, 3, 4, 5};
	// bool is = none_of(a,a+5,[](int x){return x>0;});
	// cout<<is<<endl;

	multiset<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(1);
	s.insert(2);
	auto temp = s.begin();
	temp += 2;
	// temp++;
	// temp++;
	// s.erase(temp);
	cout << *temp << endl;
	for(auto it: s) {
		cout << it << endl;
	}cout << endl;

	return 0;
}