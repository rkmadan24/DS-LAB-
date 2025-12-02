/*
    LAB PROGRAM 3: a) WAP to simulate the working of a queue of integers 
                      using an array. Provide the following operations: Insert, 
                      Delete, Display.
                      The program should print appropriate messages for queue 
                      empty and queue overflow conditions
*/


// CODE:

#include <stdio.h>
#include <stdlib.h>
#define MAX 100   

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert more elements.\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &item);

    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;

    printf("Inserted %d successfully.\n", item);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
            exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// OUTPUT:

/*

--- Queue Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 23
Inserted 23 successfully.

--- Queue Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 45
Inserted 45 successfully.

--- Queue Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 78
Inserted 78 successfully.

--- Queue Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2
Deleted element: 23

--- Queue Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
Queue elements are: 45 78 

--- Queue Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 4


*/
