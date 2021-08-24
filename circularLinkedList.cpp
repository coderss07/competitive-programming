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
	node* ptr=head;
	while(ptr->next!=head)
		ptr=ptr->next;
	head = head->next;
	ptr->next=head;
	delete todel;
}

void delAtLast(node* &head){
	if(head == NULL || head->next == head){
		delAtFirst(head);
		return;
	}
	node* temp=head;
	while(temp->next->next!=head)
		temp=temp->next;
	node* todel = temp->next;
	temp->next = head;
	delete todel;

}

void delbyVal(node* &head, int value){
	if(head == NULL || head->data == value){
		delAtFirst(head);
		return;
	}
	node* ptr=head;
	while(ptr->next!=head && ptr->next->data != value){
		ptr=ptr->next;
	}
	if(ptr->next == head){
		cout<<"Not found..."<<endl;
		return;
	}
	if(ptr->next->next == head){
		delAtLast(head);
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
	if(ptr==head || ptr->next == head){
		cout<<"Position is too large..."<<endl;
		return;
	}
	if(ptr->next->next == head){
		delAtLast(head);
		return;
	}
	node* todel=ptr->next;
	ptr->next=todel->next;
	delete todel;

}

void insertAtFirst(node* &head,int data){
	node* n = new node(data);
	if(head == NULL){
		head = n;
	}else{
		node* ptr=head;
		while(ptr->next != head)
			ptr=ptr->next;
		ptr->next=n;
	}
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
	while(temp->next != head)
		temp=temp->next;
	temp->next = n;
	n->next=head;
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
	if(ptr==head){
		cout<<"Position is too large..."<<endl;
		return;
	}
	if(ptr->next==head){
		insertAtLast(head,data);
		return;
	}
	n->next=ptr->next;
	ptr->next=n;

}

void reverse(node* &head){
	node* prev=head;
	node* curr=head;
	node* nxt=NULL;
	while(prev->next != head)
		prev=prev->next;
	nxt=curr->next;
	curr->next=prev;
	prev=curr;
	curr=nxt;
	while(curr!=head){
		nxt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nxt;
	}
	head=prev;
}

void display(node* head){
	if(head == NULL){
		cout<<"List is Empty" <<endl;
		return;
	}

	node* ptr = head;
	cout<< "HEAD->" << ptr->data << "->";
	ptr=ptr->next;
	while(ptr!=head){
		cout<< ptr->data << "->";
		ptr=ptr->next;
	}
	cout<<"HEAD"<<endl;
}

int main() {
    node* head = NULL;
    insertAtLast(head, 1);
    insertAtLast(head, 2);
    insertAtLast(head, 3);
    insertAtLast(head, 4);
    insertAtFirst(head, 0);
    // insertAtFirst(head, 1);
    // insertAtFirst(head, 7);
    display(head);
    // delAtFirst(head);
    // delAtLast(head);
    // delbyVal(head, 6);
    // delByPos(head, 4);
    // insertByPos(head,6,6);
    // delbyVal(head,2);
    reverse(head);
    display(head);
	return 0;
}
