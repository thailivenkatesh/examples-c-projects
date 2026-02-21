#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};

void add_at_begin(struct node **head, int data){
	struct node *new = malloc(sizeof(struct node));
	new->data = data;
	new->link = 0;
	new->link = *head;
	*head = new;
	//return temp;
}
void add_at_pos(struct node *head, int data, int pos){
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = 0;
	int index=1;
	while(index < pos -1){
	head = head->link;
	index++;
	}	
	temp->link = head->link;
	head->link = temp;
}
void add_at_end(struct node *head, int data){
	struct node * last = malloc(sizeof(struct node));
	last->data=data;
	last->link=0;
	while(head->link !=0){
		head = head->link;
	}
	last->link=head->link;
	head->link=last;
}
struct node * del_at_begin(struct node *head){
	if(head == NULL){
		printf("Given List is Empty\n");
	}else{
		struct node *del = head;
		head = head->link;
		free(del);
		del=0;
	}
	return head;
}
struct node * del_at_pos(struct node * head, int pos){
	struct node *del_cur = head;
	struct node *del_prev = head;
	if(head == NULL){
		printf("Given List is Empty\n");
	}
	else{
		while(pos > 1){
			del_prev = del_cur;
			del_cur = del_cur->link;
			pos--;
		}
			del_prev->link = del_cur->link;
			free(del_cur);
			del_cur=0;
	}
	return head;
}
struct node * del_at_end(struct node *head){
	struct node *del_end = head;
	struct node *del_temp = head;
	while(del_end->link != NULL){
		del_temp = del_end;
		del_end = del_end->link;
	}
	del_temp->link = 0;
	free(del_end);
	return head;
}
struct node * rev_list(struct node *head){
	struct node *curr = head;
	struct node *prev = NULL;
	struct node *next = NULL;
	while(curr != 0){
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	return head = prev;	
}

struct node * swapNodes(struct node* head, int x, int y)
{
	struct node *prevX = NULL, *currX = head;
	struct node *prevY = NULL, *currY = head;
	
    if (x == y)
        return 0;
 
    while (currX->data != x) {
        prevX = currX;
        currX = currX->link;
    }
  
    while (currY->data != y) {
		prevY = currY;
        currY = currY->link;
    }
 
    if (prevX != NULL)
        prevX->link = currY;
    else
        head = currY;
	
    if (prevY != NULL)
        prevY->link = currX;
    else 
        head = currX;

    struct node* temp = currY->link;
    currY->link = currX->link;
    currX->link = temp;
	return head;
}
void traversal(struct node *head){
	struct node *ptr = head;
	while(ptr != 0){
		printf("%d\t",ptr->data);
		ptr = ptr->link;
	}printf("\n");
}
void length(struct node *head){
	int count=0;
	struct node *ptr = head;
	while(ptr != 0){
		//printf("%d\t",ptr->data);
		ptr = ptr->link;
		count++;
	}
	printf("\nLength of list is %d\t",count);
}	

void main(){
	struct node *head = malloc(sizeof(struct node));
	head->data=23;
	head->link=0;
	struct node *ptr = head;
	//head = add_at_begin(head,96);
	add_at_begin(&head,96);
	add_at_begin(&head,67);
	add_at_begin(&head,34);
	add_at_begin(&head,83);
	add_at_pos(head,45,4);
	add_at_end(head,109);
	head = del_at_begin(head);
	head = del_at_pos(head,2);
	head = del_at_end(head);
	head = rev_list(head);
	traversal(head);  // For printing purpose
	head = swapNodes(head,23,34);
	traversal(head); // For printing purpose
	length(head);
}