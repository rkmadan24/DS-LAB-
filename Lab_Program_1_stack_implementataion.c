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
