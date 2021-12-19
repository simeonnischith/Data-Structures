#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* getnode(int value)
{
    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = value;
    return newnode;
}


void inorder(struct node* root)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf(" %d ",node->data);
        inorder(node->right);
    }
}

void insert(struct node** node, int value)
{
    if(node == NULL)
    {
        return(getnode(value));
    }

    if(node->data > value)
        node->left = insert(node->left,value);
    else if(root->data < value)
        node->right = insert(node->right,value);
}

void main()
{
    int val = 10;
    struct node* root = getnode(val);

    insert(root,10);
    insert(root,20);
    insert(root,30);





}
