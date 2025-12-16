#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// creation of linked list
struct node* createList()
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
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}


// Displaying linked list
void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}



//sorting of linked list
struct node* sortList(struct node *head)
{
    struct node *i, *j;
    int temp;

    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}


//Reversing of linked list
struct node* reverseList(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


//concatenation of two linked list
struct node* concatenate(struct node *head1, struct node *head2)
{
    struct node *temp = head1;

    if(head1 == NULL)
        return head2;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}



int main()
{
    struct node *list1, *list2;

    printf("Create First List\n");
    list1 = createList();

    printf("Create Second List\n");
    list2 = createList();

    printf("\nFirst List: ");
    display(list1);

    printf("Second List: ");
    display(list2);

    list1 = sortList(list1);
    printf("\nSorted First List: ");
    display(list1);

    list1 = reverseList(list1);
    printf("Reversed First List: ");
    display(list1);

    list1 = concatenate(list1, list2);
    printf("Concatenated List: ");
    display(list1);

    return 0;
}
