// Implementation of Linked List

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int createNOde();
void insAtBeg();
void insAtSp();
void insAtEnd();
void delAtBeg();
void delAtSp();
void delAtEnd();

int data, pos;

/* self referential structure */
struct node{
	int info;
	struct node *next;
};


/*
struct node *start = NULL: This pointer, named start, is used to keep track of the first node (head) of the linked list.
 It is initialized to NULL, indicating that the linked list is currently empty.

struct node *newnode: This pointer, named newnode, is used to create a new node 
dynamically when inserting elements into the linked list.

struct node *temp: This pointer, named temp, is typically used for traversing through 
the linked list during operations like searching, deletion, or iterating through the list.

struct node *temp1: This pointer, named temp1, is another temporary pointer
 that might be used during various operations on the linked list.
 */
struct node *start = NULL, *newnode, *temp, *temp1;

int createNode(){
	newnode=(struct node*)malloc(sizeof(struct node*));
}

void insAtBeg(){
	createNode();
	printf("\nEnter any data:");
	scanf("%d", &data);
	newnode->info=data;
	if(start==NULL){
		start=newnode;
		newnode->next=NULL;
	}
	else{
		newnode->next=start;
		start=newnode;
	}
}

void insAtSp(){
	createNode();
	printf("\nEnter any data:");
	scanf("%d", &data);
	newnode->info=data;
	printf("Enter position to insert:");
	scanf("%d", &pos);
	temp=start;
	int i;
		for(i=1; i<pos-1; i++){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
}

void insAtEnd(){
	createNode();
	printf("\nEnter any data:");
	scanf("%d", &data);
	newnode->info=data;
	newnode->next=NULL;
	if(start==NULL){
		start=newnode;
	}
	else{
		temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void display(){
	if(start==NULL){
		printf("\nList is empty");
	}
	else{
		temp=start;
		while(temp!=NULL){
			printf("%d\t", temp->info);
			temp=temp->next;
		}
	}
}

void delAtBeg(){
	if(start==NULL){
		printf("\nList is empty");
	}
	else{
		temp=start;
		start=start->next;
		free(temp);
	}
}

void delAtSp(){
	int i;
	if(start==NULL){
		printf("\nList is empty");
	}
	else{
		printf("\nEnter the position of element to delete:");
		scanf("%d", &pos);
		temp=start;
		for(i=1; i<pos-1; i++){
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp1->next;
		printf("\nDeleted node is: %d",temp1->info);
		free(temp1);
	}
}

void delAtEnd(){
	if(start==NULL){
		printf("\nList is empty");
	}
	else if(start->next=NULL){
		temp=start;
		start=NULL;
		free(temp);
	}
	else{
		temp=start;
		while(temp->next!=NULL){
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=NULL;
		free(temp);
	}
}

main(){
	int ch;
	printf("\n1.Insert at beginning.\n2.Insert at specific position\n3.Insert at End \n4.Delete at the beginning");
	printf("\n5.Delete at the specific position.\n6.Delete at the end.\n7.Display.\n8.Exit");
    while(1)
	{
			printf("\nEnter your choice:");
	scanf("%d", &ch);
	switch(ch){
		case 1:
			insAtBeg();
			break;
		case 2:
			insAtSp();
			break;
		case 3:
			insAtEnd();
			break;
		case 4:
			delAtBeg();
			break;
		case 5:
			delAtSp();
			break;
		case 6:
			delAtEnd();
			break;
		case 7:
			display();
			break;
		case 8:
			exit(0);
		default:
			printf("Enter valid choice!");		
	}
	
}
}


