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
     printf(":2 pop\n");
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
		 printf("%d",stack[i]);
    }
    }
	else{
            printf("stack is empty");
        }
    
}

