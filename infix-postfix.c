/*
  conversion of infixexpression to postfix expression
  */
  
#include<stdio.h>   
#include<ctype.h>

char stack[100];    
int tos = -1;        
/*
function is used to push (add) an element x onto the stack.
*/
void push(char x)     
{
    stack[++tos] = x; 
}
/*
 //used to pop (remove) an element from the stack and return the removed character
*/
char pop()       
{
    if(tos == -1)   
        return -1;
    else
        return stack[tos--]; 
}
/*
used to determine the priority of an operator x in the given arithmetic expression
where 0 indicates the lowest priority, and 2 indicates the highest priority.
 Parentheses '(' have the lowest priority
  precedence order $  /*  +- 
  */
int priority(char x) 
{
  
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;

    // The code inside the while loop will convert the infix expression to postfix.
    
    while(*e != '\0')
    {
        // The following conditions are used to process each character in the expression.
        
        if(isalnum(*e))  // If the character is an alphanumeric character (operand).
            printf("%c ", *e);
        else if(*e == '(')  // If the character is an opening parenthesis '('.
            push(*e);  // Push it onto the stack.
        else if(*e == ')')  // If the character is a closing parenthesis ')'.
        {
            // Pop and print operators from the stack until an opening parenthesis is encountered.
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            // The character is an operator, so handle the operator precedence.
            while(priority(stack[tos]) >= priority(*e))
                printf("%c ", pop());
            push(*e);
        }
        e++;  // Move to the next character in the expression.
    }

    // After processing all characters, pop and print any remaining operators in the stack.
    while(tos != -1)
    {
        printf("%c ", pop());
    }

    return 0;
}

/*
Enter the expression : (A+B*C/D)+E*F-(G*H+I-J)

A B C * D / + E F * + G H * I + J - -
--------------------------------
Process exited after 85.28 seconds with return value 0
Press any key to continue . . .*/
