/*
linked list traverse

    ------------------------------              ------------------------------
    |              |             |            \ |              |             |
    |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
    |              |             |            / |              |             |
    ------------------------------              ------------------------------
    */
#include<stdio.h>
#include<stdlib.h>
/*
self refrential structure
*/
struct Node{
	int data;
	struct Node*next;
};

void linkedlisttraverse(struct Node*ptr){
	while(ptr!=NULL){
		printf("Elements:%d\n",ptr ->data);
		ptr=ptr->next;
	}
}
int main(){
	struct Node*head;
	struct Node*second;
	struct Node*third;
		
	//Allocate memory for node in linked list in heap 
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	
	//link first and second node
	head->data=7;
	head->next=second;
	
	second->data=11;
	second->next=third;
	
	third->data=77;
	third->next=NULL;
	linkedlisttraverse(head);
	
		return 0;
}
/*
Elements:7
Elements:11
Elements:77

--------------------------------
Process exited after 1.051 seconds with return value 0
Press any key to continue . . .




