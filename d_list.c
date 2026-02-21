#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node* next;
};

void main(){
	struct node *head = malloc(sizeof(struct node));
	head->prev = NULL;
	head->data = 45;
	head->next = NULL;
	struct node *ptr = head;
	
	while(ptr != NULL){
		printf("%d",ptr->data);
		ptr = ptr->next;
	}
	
	
}