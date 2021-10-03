#include<bits/stdc++.h>

using namespace std;

void insert(stack<int> &s, int data){

	if(s.empty()){
		s.push(data);
		return;
	}
	int topdata=s.top();
	s.pop();
	insert(s, data);
	s.push(topdata);

}

void reverse(stack<int> &s){

	if(s.empty()){
		return;
	}

	int data = s.top();
	s.pop();
	reverse(s);
	insert(s, data);

}

void display(stack<int> s){
	while(!s.empty()){
		int e = s.top();
		cout << e << " ";
		s.pop();
	}cout << endl;

}

int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	
	display(s);
	reverse(s);
	display(s);
	
	return 0;
}
