#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node * head = 0;
struct Node * newNode, * temp;

// CREATE LINKED LIST
void createList() {
    int n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = 0;

        if (head == 0) {
            head = newNode;
        } else {
            temp = head; 
            while (temp->next != 0) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// INSERT AT BEGINNING
void insertAtBeginning() {
    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// INSERT AT ANY POSITION
void insertAtPosition() {
    int pos, value;
    printf("Enter position to insert (starting from 1): ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1 && temp != 0; i++) {
        temp = temp->next;
    }

    if (temp == 0) {
        printf("Position out of range!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// INSERT AT END
void insertAtEnd() {
    int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = 0;

    if (head == 0) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != 0) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//DISPLAY LINKED LIST
void displayList() {
    if (head == 0) {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    while (temp != 0) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// MAIN FUNCTION
int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Any Position\n");
        printf("4. Insert at End\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); 
            break;
            case 2: insertAtBeginning(); 
            break;
            case 3: insertAtPosition(); 
            break;
            case 4: insertAtEnd(); 
            break;
            case 5: displayList(); 
            break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
