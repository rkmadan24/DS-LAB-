/*
    Lab_Program_implementation_of_doubly_linked_list_for_characters
*/


// CODE:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(Node* head) {
    Node* temp = head;
    printf("Doubly Linked List:\n");
    printf("-------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-5s | %-10s |\n", "Node Addr", "Prev Addr", "Data", "Next Addr");
    printf("-------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("|%-10p|%-10p|%-5c|%-10p|\n",
               (void*)temp,
               (void*)temp->prev,
               temp->data,
               (void*)temp->next);
        temp = temp->next;
    }
     printf("-------------------------------------------------------------\n");
}

int main(void) {
    Node* N1 = createNode('A');
    Node* N2 = createNode('B');
    Node* N3 = createNode('C');
    Node* N4 = createNode('D');
    Node* N5 = createNode('E');

    N1->next = N2;
    N2->prev = N1;
    N2->next = N3;
    N3->prev = N2;
    N3->next = N4;
    N4->prev = N3;
    N4->next = N5;
    N5->prev = N4;

    display(N1);

    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);

    return 0;
}

// OUTPUT:

/*
Doubly Linked List:
-------------------------------------------------------------
| Node Addr  | Prev Addr  | Data  | Next Addr  |
-------------------------------------------------------------
|00000000001C1480|0000000000000000|A    |00000000001C14A0|
|00000000001C14A0|00000000001C1480|B    |00000000001C14C0|
|00000000001C14C0|00000000001C14A0|C    |00000000001C14E0|
|00000000001C14E0|00000000001C14C0|D    |00000000001C1500|
|00000000001C1500|00000000001C14E0|E    |0000000000000000|
-------------------------------------------------------------
*/
