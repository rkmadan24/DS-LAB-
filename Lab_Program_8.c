/*
    LAB PROGRAM 8 : Write a program 
                    a) To construct a binary Search tree. 
                    b) To traverse the tree using all the methods i.e., in-order, 
                       preorder and post order 
                    c) To display the elements in the tree.

*/

// CODE:

#include <stdio.h>
#include <stdlib.h>


//DEFINE NODE STRUCTURE
struct node
{
    int data;
    struct node *left;
    struct node *right;
};


//CREATE NEW NODE
struct node* createNode(int data)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}



//INSERT FUNCTION
struct node* insert(struct node *root, int data)
{
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

//INORDER TRAVERSAL
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


//PREORDER TRAVERSAL
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}



//POSTORDER TRAVERSAL
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}



//MAIN FUNCTION
int main()
{
    struct node *root = NULL;
    int n, i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}

// OUTPUT:

/*

Enter number of nodes: 5
Enter values:
32
124
43
85
35

Inorder Traversal: 32 35 43 85 124   
Preorder Traversal: 32 124 43 35 85  
Postorder Traversal: 35 85 43 124 32 

*/
