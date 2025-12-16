/* 
    LAB PROGRAM 6 b):  WAP to Implement Single Link List to simulate Stack & 
                       Queue Operations. 

*/

// CODE:


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;        
struct node *front = NULL;      
struct node *rear = NULL;      



//STACK OPERATIONS

void push(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Pushed %d into stack\n", value);
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Popped %d from stack\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStack()
{
    struct node *temp = top;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



//QUEUE OPERATIONS

void enqueue(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued %d into queue\n", value);
}

void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Dequeued %d from queue\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue()
{
    struct node *temp = front;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            displayStack();
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

// OUTPUT:

/*

--- MENU ---      
1. Push (Stack)   
2. Pop (Stack)    
3. Display Stack  
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue  
7. Exit
Enter choice: 1   
Enter value: 34
Pushed 34 into stack

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 1
Enter value: 65 
Pushed 65 into stack

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 1
Enter value: 22
Pushed 22 into stack

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 2
Popped 22 from stack

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 3
Stack elements: 65 34 

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 4
Enter value: 56
Enqueued 56 into queue

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 489
Invalid choice

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 4
Enter value: 32
Enqueued 32 into queue

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 4
Enter value: 90
Enqueued 90 into queue

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 5
Dequeued 56 from queue

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 6
Queue elements: 32 90 

--- MENU ---
1. Push (Stack)
2. Pop (Stack)
3. Display Stack
4. Enqueue (Queue)
5. Dequeue (Queue)
6. Display Queue
7. Exit
Enter choice: 7

*/

