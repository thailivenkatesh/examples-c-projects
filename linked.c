//rev
#include <stdio.h>
#include<stdlib.h>
struct node{
     int data;
    struct node *link;
};
struct node *add_at_begin(struct node *head, int data){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=0;
    ptr->link=head;
    head=ptr;
    return head;
}

struct node *reverseprint(struct node* ptr){
   struct node* prev=0;
   struct node* next=0;
    while(ptr!=0){
		  next=ptr->link;
		  ptr->link=prev;
		  prev=ptr;
		  ptr=next;
        }
    ptr=prev;  
  return ptr;
}

int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=0;
    head->link=0;
	struct node *ptr;
   head=add_at_begin(head,1);
   head=add_at_begin(head,2);  
   head=add_at_begin(head,3);
   head=add_at_begin(head,4);    
    ptr=head;   
    while(ptr!=0){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
       }
   head=(struct node *)reverseprint(head);
   struct node *ptr1;
   ptr1=head;
   printf("\nrevlist\n");
   
   while(ptr1!=0) {
        printf("%d\t",ptr1->data);
        ptr1=ptr1->link;
    }
    return 0;
}
