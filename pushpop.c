/*
  Implement push and pop operation using stack:
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int stack[5],top=-1;
void push();
void pop();
void show();
void main(){
    int ch;
    printf("1: push\n");
     printf("2: pop\n");
      printf("3: show\n");
       printf("4: exit\n");

while(1){
    printf("\nEnter choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        push();
        break;
         case 2:
        pop();
        break;
         case 3:
        show();
        break;
         case 4:
        exit(0);
        break;
        default:
        printf("Invalid option");

    }

  }
}
/*
insertion of element in stack is done through push operation
*/
void push(){
    int item;
    if(top==5-1){
      printf("Stack is full");  
    }
    else{
        printf("push element in stack:");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
    }
}
/*
deletion of element is done through pop operation 
*/
void pop(){
	int items;
    if(top==-1){
        printf("stack is empty");
    
    }
    else{
       printf("popped %d",stack[top]);
        top=top-1;
    }
}
void show()
{
    int i;
    if(top>=0){
        printf("Stack elements:\n");
        for(i=top;i>=0;i--)             
	 {
		 printf("%d\t",stack[i]);
    }
    }
	else{
            printf("stack is empty");
        }
    
}
/*
1: push
2 pop
3: show
4: exit

Enter choice:1
push element in stack:4

Enter choice:1
push element in stack:6

Enter choice:1
push element in stack:9

Enter choice:1
push element in stack:7

Enter choice:3
Stack elements:
7       9       6       4
Enter choice:2
popped 7               //in stack LIFO is opeates
Enter choice:3
Stack elements:
9       6       4
Enter choice:
*/

