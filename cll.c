#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* delFirst(struct node* tail)
{ 
 if(tail == NULL) 
 return tail; 
 if(tail->next == tail)
 {
 free(tail); 
 tail = NULL; 
 return tail; 
 }
 struct node* temp = tail->next; 
 tail->next = temp->next; 
 free(temp); 
 temp = NULL; 
 return tail; 
}

struct node* addatpos(struct node* tail, int data, int pos) 
{
 struct node* p = tail->next; 
 struct node* newP = malloc(sizeof(struct node)); 
 newP->data = data; 
 newP->next = NULL; 
 while(pos != 2)
 { 
 p = p->next; 
 pos--; 
 }
 newP->next = p->next;
 p->next = newP; 
 if(p == tail)
 {
 tail = tail->next; 
 }
 return tail; 
}


struct node* addatbegin(struct node* tail,int data){
	struct node* newp;
	newp=malloc(sizeof(struct node));
	newp->data=data;
	newp->next=tail->next;
	tail->next=newp;
	//tail=tail->next;
	return tail;	
}
struct node* addatend(struct node* tail,int data){
	struct node* newp;
	newp=malloc(sizeof(struct node));
	newp->data=data;
	newp->next=tail->next;
	tail->next=newp;
	tail=newp;
	return tail;	
}

struct node* addtoempty(){
	struct node* tail;
	tail=malloc(sizeof(struct node));
	tail->data=4;
	tail->next=tail;	
	return tail;	
}
void print(struct node* tail)
{ 
 struct node* p = tail->next; 
 do
 { 
 printf("%d\t ", p->data); 
 p = p->next;
 } while(p!=tail->next); 
}

int main(){
    struct node* tail;
	tail=addtoempty();
	tail=addatbegin(tail,44);
	tail=addatbegin(tail,45);
	tail=addatbegin(tail,46);	
	tail=addatend(tail,49);
	print(tail);
	tail=addatpos(tail,50,3);
	printf("\n");
	delFirst(tail);
	print(tail);
	
	return 0;
}