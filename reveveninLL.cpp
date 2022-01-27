// Author : Sarthak Sharma
#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

class node {
	public:
		int data;
		node* next;
		node(int d) {
			data = d;
			next = NULL;
		}
};

void insertAtLast(node* &head, int data){
	node* n = new node(data);
	if(head == NULL){
		head = n;
		return;
	}
	node* temp = head;
	while(temp->next)
		temp = temp->next;
	temp->next = n;
}

void display(node* head){
	node* ptr = head;
	while(ptr){
		cout << ptr->data << "->";
		ptr = ptr->next;
	}
	cout << "NULL" << endl;
}

void rev(node*& head, node* &prev, node* &st, node* ed) {
	node* pr = ed;
	node* curr = st;
	node* nxt = NULL;
	while(curr != ed){
		nxt = curr->next;
		curr->next = pr;
		pr = curr;
		curr = nxt;
	}
	if(prev) prev->next = pr;
	else head = pr;
}

void recover(node* &head) {
	node* ptr = head;
	node* st = nullptr;
	if(head->data % 2 == 0) st = head;
	node* prev = nullptr;
	while(ptr) {
		if(!st && ptr->next && ptr->next->data % 2 == 0) {
			st = ptr->next;
			prev = ptr;
		}
		if(st && (!ptr->next || ptr->next->data % 2 != 0)) {
			rev(head, prev, st, ptr->next);
			st = nullptr;
		}
		ptr = ptr->next;
	}
}

int main() {
	clock_t begin_69 = clock();
	fast_io;
	int n; cin >> n;
	node* head = NULL;
	for(int i = 0; i < n; i++) {
		int data; cin >> data;
		insertAtLast(head, data);
	}
	display(head);
	recover(head);
	display(head);
	
	#ifndef ONLINE_JUDGE
		clock_t terminator_69 = clock();
		cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	#endif 
	return 0;
}