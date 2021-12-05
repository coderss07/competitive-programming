#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;

};
struct node* del_begin(struct node *head)
{
	if(!head) {
		return head;
	}
	struct node* temp = head;
	head = head->next;
	free(temp);
	return head;
}
struct node* del_end(struct node *head )
{
	if(!head || !head->next) // no node or only one node;
	{
		del_begin(head);
		return head;
	}
    struct node *ptr =head;
    while (ptr->next->next!= NULL)
    {
        ptr=ptr->next;
    }
    struct node *temp = ptr->next;
    free(temp);
    ptr->next = NULL;
    return head;
}
// void del_middle(struct nodfe)
struct node* create_node(int info)
{
   struct node* ptr;
   ptr=(struct node*)malloc(sizeof(struct node));
   ptr->data=info;
   ptr->next =NULL;
   return ptr;
}
struct node* insert(struct node *head, int data)
{
    struct node *ptr;
    ptr= create_node(data);
    if(!head)
    {
        return ptr;
    }
    ptr ->next = head;
    head =ptr;
    return head;

}
void display (struct node* head)
{
    struct node *ptr =head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;

    }
}
int main(){
    struct node *head=NULL;
    head = insert(head,23);
    head = insert(head,32);
    head = insert(head,65);
    head = del_begin(head);
    display(head);
    printf("\n");
    head = del_end(head);
    display(head);

    return 0;


}