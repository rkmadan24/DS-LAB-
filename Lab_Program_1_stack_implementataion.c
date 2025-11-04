/*
    LAB PROGRAM 1:Write a program to simulate the working of stack using an 
                  array with the following: 
                  a) Push 
                  b) Pop 
                  c) Display 
                  The program should print appropriate messages for stack 
                  overflow, stack underflow 
*/


//CODE:

#include <stdio.h>
#define MAX 100

void push(int);
void pop();
void display();

int stack[MAX];
int top = -1;

int main()
{
    int choice, value;
    while (1)
    {
        printf("FOLLOWING ARE THE STACK OPERATIONS\n");
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed (inserted at the top): ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
   
}


void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d Pushed to stack\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Cannot pop from empty stack\n");
    }
    else
    {
        printf("%d Popped from stack\n", stack[top--]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

/*
OUTPUT:
------
FOLLOWING ARE THE STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter your choice: 1
Enter the value to be pushed (inserted at the top): 25
25 Pushed to stack
FOLLOWING ARE THE STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter your choice: 1
Enter the value to be pushed (inserted at the top): 45
45 Pushed to stack
FOLLOWING ARE THE STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter your choice: 1
Enter the value to be pushed (inserted at the top): 32
32 Pushed to stack
FOLLOWING ARE THE STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter your choice: 3
Stack elements are:
32
45
25
FOLLOWING ARE THE STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter your choice: 2
32 Popped from stack
FOLLOWING ARE THE STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter your choice: 3
Stack elements are:
45
25
FOLLOWING ARE THE STACK OPERATIONS
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter your choice: 4

*/
//PROGRAM EXECUTION STOPS HERE
