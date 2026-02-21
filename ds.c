//add at end
#include <stdio.h>
#include<stdlib.h>
struct node
{
     int data;
    struct node *link;
};
struct node add_at_end(struct node *ptr,unsigned int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    while(ptr->link!=0)
    ptr=ptr->link;
    ptr->link=temp;
    //return temp;
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=0;
    struct node *ptr=head;
    add_at_end(ptr,98);
    add_at_end(ptr,99);
    add_at_end(ptr,98);
    add_at_end(ptr,99);
    ptr=head;
    while(ptr!=0)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    

    return 0;
}

//add at begin
#include <stdio.h>
#include<stdlib.h>
struct node
{
     int data;
    struct node *link;
};
struct node* add_at_begin(struct node *head, int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=0;
    ptr->link=head;
    head=ptr;
    return head;
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=0;
     struct node *ptr=malloc(sizeof(struct node));
    ptr->data=46;
     ptr->link=0;
     head->link=ptr;
     
    int data=3;
   head=add_at_begin(head,data);
      int data1=5;
   head=add_at_begin(head,data1);
    
    ptr=head;
    while(ptr!=0)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    

    return 0;
}
//add at certain
#include <stdio.h>
#include<stdlib.h>
struct node
{
     int data;
    struct node *link;
};
struct node add_at_begin(struct node head, int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=0;
    ptr->link=head;
    head=ptr;
    return head;
}
void add_at_pos(struct node *head ,int pos,int data)
{
    struct node *ptr=head; 
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    pos--;
    while(pos!=1)
    {
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=0;
     struct node *ptr=malloc(sizeof(struct node));
    ptr->data=46;
     ptr->link=0;
     head->link=ptr;
     
    int data=3;
   head=add_at_begin(head,data);
      int data1=5;
   head=add_at_begin(head,data1);
   int data2=15;
    int pos=3;
    add_at_pos(head,pos,data2);
    
    ptr=head;
    while(ptr!=0)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    

    return 0;
}



//rev
#include <stdio.h>
#include<stdlib.h>
struct node
{
     int data;
    struct node *link;
};
struct node* add_at_begin(struct node *head, int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=0;
    ptr->link=head;
    head=ptr;
    return head;
}

struct node* reverseprint(struct node* ptr)
{
  struct node* prev=0;
   struct node* next=0;
  while(ptr!=0)
  {
      next=ptr->link;
      ptr->link=prev;
      prev=ptr;
      ptr=next;
  }
  ptr=prev;
  
  return ptr;
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=0;
     struct node *ptr=malloc(sizeof(struct node));
    ptr->data=46;
     ptr->link=0;
     head->link=ptr;
     
    int data=3;
   head=add_at_begin(head,data);
      int data1=5;
   head=add_at_begin(head,data1);
    
    ptr=head;
   
    while(ptr!=0)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
   head=(struct node *)reverseprint(head);
   struct node *ptr1;
      ptr1=head;
     printf("\nrevlist\n");
   
    while(ptr1!=0)
    {
        printf("%d\t",ptr1->data);
        ptr1=ptr1->link;
    }

    return 0;
}

//all in one


#include <stdio.h>
#include <stdlib.h>
struct node
{
    unsigned int data;
    struct node *link;
};
void print(struct node *ptr)
{
     while(ptr!=0)
   {
       printf("%d\t",ptr->data);
       ptr=ptr->link;
   }
}
insert_certain(struct node* head,unsigned int data,unsigned int pos)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    struct node *ptr=head;
    if(pos==1)
    {
     temp->link=ptr;
     ptr=temp; 
     print(ptr);
    }
    else
    {
    while(pos!=2)
    {
        pos--;
        ptr=ptr->link;
    }
  temp->link=ptr->link;
  ptr->link=temp;
  print(ptr);
    }
}
void insert_end(struct node* head,unsigned int data) 
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    struct node *ptr=head;
    while(ptr->link!=0)
    ptr=ptr->link;
    ptr->link=temp;
}
struct node* insert_begin(struct node*ptr,unsigned int data) 
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    temp->link=ptr;
    ptr=temp;
    return ptr;
}
int main()
{
   struct node *head=malloc(sizeof(struct node));
   head->data=2;
   head->link=0;
   struct node *current=malloc(sizeof(struct node));
   current->data=22;
   current->link=0;
   head->link=current;
   struct node *ptr=head;
   print(ptr);
   printf("\nData after insert at begin\n");
   head=insert_begin(head,3);
   head=insert_begin(head,31);
   ptr=head;
   print(ptr);
   printf("\nData after insert at end\n");
   struct node * ptr1=head;
   insert_end(ptr1,4);
   insert_end(ptr1,41);
   ptr=head;
   print(ptr);
   printf("\nData after certaind\n");
   int data=5,pos=1;
   insert_certain(head,data,pos);
   return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    printf("%d\n", head->data);
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    printf("%d\n", current->data);
    head->link = current; // link the first node with the second node
    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current; //link the second node with the third node
    printf("%d\n", current->data, current);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("the list has %d nodes", count);
}
int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    printf("the value head->data is = %d\n", head->data);
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    printf("the value current->data is = %d\n", current->data);
    head->link = current; 
    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current; 
    printf("the value current->data is = %d\n", current->data);
    count_of_nodes(head);
    return 0;
}
