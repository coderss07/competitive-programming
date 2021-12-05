#include<bits/stdc++.h>

using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int d){
			data=d;
			next=NULL;
		}
};

void delAtFirst(node* &head){
	if(head == NULL)
		return;
	node* todel=head;
	head = head->next;
	delete todel;
}

void delAtLast(node* &head){
	if(head == NULL || head->next == NULL){
		delAtFirst(head);
		return;
	}
	node* temp=head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	node* todel = temp->next;
	temp->next = NULL;
	delete todel;

}

void delbyVal(node* &head, int value){
	if(head == NULL || head->data == value){
		delAtFirst(head);
		return;
	}
	node* ptr=head;
	while(ptr->next!=NULL && ptr->next->data != value){
		ptr=ptr->next;
	}
	if(ptr->next == NULL){
		cout<<"Not found..."<<endl;
		return;
	}
	node* todel = ptr->next;
	ptr->next=todel->next;
	delete todel;
}

void delByPos(node* &head,int pos){
	if(pos == 1 || head == NULL){
		delAtFirst(head);
		return;
	}
	node* ptr=head;
	for(int i=0; i<pos-2; i++){
		ptr=ptr->next;
	}
	if(ptr==NULL || ptr->next == NULL){
		cout<<"Position is too large..."<<endl;
		return;
	}
	node* todel=ptr->next;
	ptr->next=todel->next;
	delete todel;

}

void insertAtFirst(node* &head,int data){
	node* n = new node(data);
	n->next=head;
	head=n;
}

void insertAtLast(node* &head,int data){
	if(head == NULL){
		insertAtFirst(head,data);
		return;
	}
	node* n = new node(data);
	node* temp=head;
	while(temp->next != NULL)
		temp=temp->next;
	temp->next = n;
}

void insertByPos(node* &head,int data,int pos){
	if(pos == 1 || head == NULL){
		insertAtFirst(head, data);
		return;
	}
	node* n = new node(data);
	node* ptr=head;
	for(int i=0; i<pos-2; i++){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		cout<<"Position is too large..."<<endl;
		return;
	}
	n->next=ptr->next;
	ptr->next=n;

}

void makeCycle(node* &head, int pos) {
	node* ptr=head;
	node* startptr=head;
	int cnt=1;
	while(ptr->next!=NULL){

		if(cnt==pos){
			startptr=ptr;
		}
		ptr=ptr->next;
		cnt++;
	}
	ptr->next=startptr;
}

bool detectCycle(node* head){
	node* slowptr=head;
	node* fastptr=head;
	while(fastptr!=NULL && fastptr->next!=NULL){
		fastptr=fastptr->next->next;
		slowptr=slowptr->next;
		if(fastptr == slowptr){
			return true;
		}
	}
	return false;
}

void removeCycle(node* &head){
	node* slowptr=head;
	node* fastptr=head;
	do{
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;
	}while(slowptr!=fastptr);
	fastptr=head;
	while(fastptr->next != slowptr->next){
		fastptr=fastptr->next;
		slowptr=slowptr->next;
	}
	slowptr->next=NULL;
}

void reverse(node* &head){
	node* prev=NULL;
	node* curr=head;
	node* nxt=NULL;
	while(curr!=NULL){
		nxt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nxt;
	}
	head=prev;
}

node* reverseRecursive(node* head){

	if(head == NULL || head->next == NULL){
		return head;
	}

	node* newh=reverseRecursive(head->next);
	head->next->next=head;
	head->next=NULL;
	return newh;
}

node* reverseKnode(node* head, int k){
	node* prev=NULL;
	node* curr=head;
	node* nxt=NULL;
	int cnt=0;
	while(curr!=NULL && cnt<k){
		nxt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nxt;
		cnt++;
	}
	if(nxt!=NULL)
		head->next=reverseKnode(nxt,k);
	return prev;

}

int length(node* head){
	int l=0;
	while(head!=NULL){
		head = head->next;
		l++;
	}
	return l;
}

void append(node* &head, int k){
	int len = length(head);
	node* tail=head;
	node* ptr1;
	node* ptr2;
	int cnt=1;
	while(tail->next != NULL){
		if(cnt == len-k)
			ptr1=tail;
		if(cnt == len-k+1)
			ptr2=tail;
		tail=tail->next;
		cnt++;
	}
	tail->next=head;
	ptr1->next=NULL;
	head=ptr2;
}

void intersection(node* h1, node* h2, int pos){
	node* ptr=h1;
	pos--;
	while(ptr!=NULL && pos--){
		ptr=ptr->next;
	}
	if(ptr!=NULL){
		node* ptr1=h2;
		while(ptr1->next!=NULL)
			ptr1=ptr1->next;
		ptr1->next=ptr;

	}
}

int findIntersect(node* h1, node* h2){

	int l1=length(h1);
	int l2=length(h2);
	int cnt=0;
	node* ptr1;
	node* ptr2;	
	if(l1>l2){
		cnt=l1-l2;
		ptr1=h1;
		ptr2=h2;
	}else if(l2>l1){
		cnt=l2-l1;
		ptr1=h2;
		ptr2=h1;
	}
	while(cnt--){
		ptr1=ptr1->next;
		if(ptr1==NULL){
			return -1;
		}
	}
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1==ptr2){
			return ptr1->data;
		}
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	return -1;
}

node* merge(node* h1,node* h2){
	node* h3=NULL;
	node* ptr1=h1;
	node* ptr2=h2;
	while(ptr1!=NULL && ptr2!=NULL){
		int val;
		if(ptr1->data < ptr2->data){
			val=ptr1->data;
			ptr1=ptr1->next;
		}else if(ptr1->data > ptr2->data){
			val=ptr2->data;
			ptr2=ptr2->next;
		}
		insertAtLast(h3,val);
	}
	while(ptr1!=NULL){
		int val=ptr1->data;
		ptr1=ptr1->next;
		insertAtLast(h3,val);
	}
	while(ptr2!=NULL){
		int val=ptr2->data;
		ptr2=ptr2->next;
		insertAtLast(h3,val);
	}
	return h3;
}

void evevAfterOdd(node* head){
	node* odd=head;
	node* even=head->next;
	node* evenstart=even;
	while(odd->next!=NULL && even->next!=NULL){
		odd->next=even->next;
		odd=odd->next;
		even->next=odd->next;
		even=even->next;
	}
	if(odd->next!=NULL){
		even->next=NULL;
	}
	odd->next=evenstart;
}

/* From this 1->6->9->13->15->20->26->NULL
			To
  1->26->6->20->9->15->13->NULL
  a1->an->a2>an-1->a3->.......*/
node* ptr;

void helper(node* head) {
	if(!head) {
		return;
	}
	helper(head->next);
	if(!ptr) {
		return;
	}
	if(head == ptr || ptr->next == head) {
		head->next = NULL;
		ptr = NULL;
		return;
	}
	head->next = ptr->next;
	ptr->next = head;
	ptr = head->next;
}

void reorder(node* head) {
	ptr = head;
	helper(head);
}

void sort_list(node* head) {
	if(!head || !head->next) { // if no node exist or only one node exist then no need to sort
		return;
	} 
	node* ptr1 = head;
	node* ptr2;

	while(ptr1->next) {
		ptr2 = ptr1->next;
		while(ptr2) {
			if(ptr1->data > ptr2->data) {
				swap(ptr1->data, ptr2->data);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

void display(node* head){
	if(head == NULL){
		cout<<"List is Empty" <<endl;
		return;
	}

	node* ptr = head;
	while(ptr!=NULL){
		cout<< ptr->data << "->";
		ptr=ptr->next;
	}
	cout<<"NULL"<<endl;
}

int main() {
    node* head = NULL;
    insertAtLast(head, 9);
    insertAtLast(head, 15);
    insertAtLast(head, 6);
    insertAtLast(head, 13);
    insertAtLast(head, 1);
    insertAtLast(head, 26);
    insertAtLast(head, 20);
    display(head);
    // sort_list(head);
    // display(head);
    reorder(head);
    display(head);
    // insertAtFirst(head, 0);
    // display(head);
    // node* head1 = NULL;
    // insertAtLast(head1, 3);
    // insertAtLast(head1, 11);
    // insertAtLast(head1, 16);
    // insertAtLast(head1, 21);
    // insertAtLast(head1, 22);
    // display(head1);
    // node*  head2=merge(head, head1);
    // display(head2);
    // evevAfterOdd(head2);
    // intersection(head,head1,4);
    // cout<< findIntersect(head, head1)<<endl;
    // display(head2);
    // append(head,5);
    // head = reverseKnode(head, 3);
    // cout<< length(head) <<endl;
    // head = reverseRecursive(head);
    // makeCycle(head,3);
    // cout<< (detectCycle(head)?"YES":"NO") <<endl;
    // removeCycle(head);
    // cout<< (detectCycle(head)?"YES":"NO") <<endl;
    // delbyVal(head, 6);
    // delByPos(head, 6);
    // insertByPos(head,6,1);
    // delbyVal(head,4);
    // reverse(head);
    // display(head);
	return 0;
}
