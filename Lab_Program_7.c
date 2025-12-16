#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};



// creation of doubly linked list
struct node* create()
{
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    return head;
}


//display doubly linked list
void display(struct node *head)
{
    printf("List: ");
    while(head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


//Insert to the left of the given value
struct node* insertLeft(struct node *head, int val, int newdata)
{
    struct node *temp = head, *newnode;

    while(temp != NULL && temp->data != val)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;

    newnode->next = temp;
    newnode->prev = temp->prev;

    if(temp->prev != NULL){
        temp->prev->next = newnode;
    }
    else{
        head = newnode;
    }
    temp->prev = newnode;
    return head;
}


//Deletion of a node by a value
struct node* deleteValue(struct node *head, int val)
{
    struct node *temp = head;

    while(temp != NULL && temp->data != val)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}



int main()
{
    struct node *head;
    int choice, val, newdata;

    head = create();
    display(head);

    printf("Enter value to insert left of: ");
    scanf("%d", &val);
    printf("Enter new value: ");
    scanf("%d", &newdata);
    head = insertLeft(head, val, newdata);
    display(head);

    printf("Enter value to delete: ");
    scanf("%d", &val);
    head = deleteValue(head, val);
    display(head);

    return 0;
}
