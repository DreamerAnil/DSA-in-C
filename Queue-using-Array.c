/*
 * C Program to Implement a Queue using an Array
 */
#include <stdio.h>
 
#define MAX 50
 
void insert();
void delete();
void display();
int queue_array[MAX];
int r = - 1;
int f = - 1;
main()
{       int ch;
	    printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
    while (1)
    {
       
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            insert();
            break;
            
            case 2:
            delete();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } 
    } 
} 
 
void insert()
{
    int item;
    if (r == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (f == - 1)
        /*If queue is initially empty */
        f = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &item);
        r = r + 1;
        queue_array[r] = item;
    }
} 
 
void delete()
{
    if (f == - 1 || f > r)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[f]);
        f = f + 1;
    }
} /* End of delete() */
 
void display()
{
    int i;
    if (f == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = f; i <= r; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 
/*
1.Insert element to queue
2.Delete element from queue
3.Display all elements of queue
4.Quit
Enter your choice : 1
Inset the element in queue : 5
Enter your choice : 1
Inset the element in queue : 8
Enter your choice : 1
Inset the element in queue : 10
Enter your choice : 1
Inset the element in queue : 20
Enter your choice : 3
Queue is :
5 8 10 20
Enter your choice : 2
Element deleted from queue is : 5 //FIFO (first element inserted will be first element deleted)
Enter your choice : 3
Queue is :
8 10 20
Enter your choice : 4

--------------------------------
Process exited after 87.39 seconds with return value 1
Press any key to continue . . .*/
