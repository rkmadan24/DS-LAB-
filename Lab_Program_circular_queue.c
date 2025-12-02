#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int cqueue[MAX];
int front = -1, rear = -1;

// INSERT into circular queue
void insert() {
    int item;

    // Check overflow
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    // First insertion
    if (front == -1) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    cqueue[rear] = item;
    printf("Inserted %d successfully.\n", item);
}

// DELETE from circular queue
void delete() {
    // Check underflow
    if (front == -1) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", cqueue[front]);

    // If only one element
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

// DISPLAY the queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");

    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

// MAIN FUNCTION
int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); 
            break;
            case 2: delete(); 
            break;
            case 3: display(); 
            break;
            case 4: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
