/*
    LAB PROGRAM 5 : WAP to Implement Singly Linked List with following 
                    operations 
                    a) Create a linked list. 
                    b) Deletion of first element, specified element and last 
                       element in the list. 
                    c) Display the contents of the linked list.

*/

// CODE:

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

// DELETE NODE AT FIRST POSITION
void deleteAtFirst() {
    if (head == 0) {
        printf("List is empty. No nodes to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node at first position deleted successfully.\n");
}   


// DELETE NODE AT THE END
void deleteAtEnd() {
    if (head == 0) {
        printf("List is empty. No nodes to delete.\n");
        return;
    }
    if (head->next == 0) {
        free(head);
        head = 0;
        printf("Node at end position deleted successfully.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != 0) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = 0;
    printf("Node at end position deleted successfully.\n");
}

// DELETE NODE AT SPECIFIC POSITION
void deleteAtPosition(int position) {
    if (head == 0) {
        printf("List is empty. No nodes to delete.\n");
        return;
    }
    if (position == 1) {
        deleteAtFirst();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp->next == 0) {
            printf("Position out of bounds.\n");
            return;
        }
        temp = temp->next;
    }
    struct Node* nodeToDelete = temp->next;
    if (nodeToDelete == 0) {
        printf("Position out of bounds.\n");
        return;
    }
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node at position %d deleted successfully.\n", position);
}

// DISPLAY LINKED LIST
void displayList() {
    if (head == 0) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != 0) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, position;

    

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Delete at First Position\n");
        printf("3. Delete at End Position\n");
        printf("4. Delete at Specific Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                deleteAtFirst();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 5:
                displayList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;

}


// OUTPUT:


/*

Menu:
1. Create Linked List
2. Delete at First Position
3. Delete at End Position
4. Delete at Specific Position
5. Display List
6. Exit
Enter your choice: 1
Enter the number of nodes: 5
Enter value for node 1: 32
Enter value for node 2: 4556
Enter value for node 3: 65
Enter value for node 4: 23
Enter value for node 5: 56

Menu:
1. Create Linked List
2. Delete at First Position
3. Delete at End Position
4. Delete at Specific Position
5. Display List
6. Exit
Enter your choice: 2
Node at first position deleted successfully.

Menu:
1. Create Linked List
2. Delete at First Position
3. Delete at End Position
4. Delete at Specific Position
5. Display List
6. Exit
Enter your choice: 4
Enter position to delete: 2
Node at position 2 deleted successfully.

Menu:
1. Create Linked List
2. Delete at First Position
3. Delete at End Position
4. Delete at Specific Position
5. Display List
6. Exit
Enter your choice: 3
Node at end position deleted successfully.

Menu:
1. Create Linked List
2. Delete at First Position
3. Delete at End Position
4. Delete at Specific Position
5. Display List
6. Exit
Enter your choice: 5
Linked List: 4556 -> 23 -> NULL

Menu:
1. Create Linked List
2. Delete at First Position
3. Delete at End Position
4. Delete at Specific Position
5. Display List
6. Exit
Enter your choice: 6

*/
