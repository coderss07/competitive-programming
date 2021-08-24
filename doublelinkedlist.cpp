#include<bits/stdc++.h>

using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		node(int d){
			data=d;
			next=NULL;
			prev=NULL;
		}
};

void delAtFirst(node* &head){
	if(head == NULL)
		return;
	node* todel=head;
	head = head->next;
	if(head!=NULL)
		head->prev=NULL;
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
	if(ptr->next->next == NULL){
		delAtLast(head);
		return;
	}
	node* todel = ptr->next;
	ptr->next=todel->next;
	todel->next->prev=ptr;
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
	if(ptr->next->next==NULL){
		delAtLast(head);
		return;
	}
	node* todel=ptr->next;
	ptr->next=todel->next;
	todel->next->prev=ptr;
	delete todel;

}

void insertAtFirst(node* &head,int data){
	node* n = new node(data);
	n->next=head;
	if(head != NULL)
		head->prev=n;
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
	n->prev=temp;
}

void insertByPos(node* &head,int data,int pos){
	if(pos == 1 || head == NULL){
		insertAtFirst(head, data);
		return;
	}
	node* ptr=head;
	for(int i=0; i<pos-2; i++){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		cout<<"Position is too large..."<<endl;
		return;
	}
	if(ptr->next==NULL){
		insertAtLast(head,data);
		return;
	}
	node* n = new node(data);
	n->next=ptr->next;
	ptr->next->prev=n;
	n->prev=ptr;
	ptr->next=n;


}

void reverse(node* head){
	if(head == NULL){
		cout<<"List is Empty" <<endl;
		return;
	}

	node* ptr = head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	cout<<"NULL<->";
	while(ptr!=NULL){
		cout<< ptr->data << "<->";
		ptr=ptr->prev;
	}
	cout<<"NULL"<<endl;
}

void display(node* head){
	if(head == NULL){
		cout<<"List is Empty" <<endl;
		return;
	}

	node* ptr = head;
	cout<<"HEAD->";
	while(ptr!=NULL){
		cout<< ptr->data << "<->";
		ptr=ptr->next;
	}
	cout<<"NULL"<<endl;
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
    reverse(head);
    // delAtFirst(head);
    // delAtLast(head);
    // delbyVal(head, 0);
    delByPos(head, 1);
    // insertByPos(head,6,3);
    // delbyVal(head,2);
    display(head);
	return 0;
}
