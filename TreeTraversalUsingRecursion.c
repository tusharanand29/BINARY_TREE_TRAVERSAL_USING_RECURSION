#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;

}*root=NULL;

struct node* create_node(int val)
{
    struct node *current ;
    current=(struct node*)malloc(sizeof(struct node));
    current->right=current->left=NULL;
    current->data=val;

    return current ;
}

void inorder(struct node *root) /// LIKE INFIX NOTATION A+B PROCESS IN ORDER OF (LEFT SUBTREE CURRENT ROOT RIGHT SUBTREE)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root) /// LIKE POSTFIX NOTATION AB+ PROCESS IN ORDER OF (LEFT SUBTREE RIGHT SUBTREE CURRENT ROOT)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(struct node *root) /// LIKE PREFIX NOTATION +AB PROCESS IN ORDER OF ( CURRENT ROOT LEFT SUBTREE RIGHT SUBTREE)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int Binary_search(struct node *root,int n)
{
    int temp=0;
    if(root==NULL)
        return 0;
    else
    {
        if(n==root->data)
            return 1;
        else
        {
            temp=Binary_search(root->l,n);
            if(temp!=0)
                return temp;
            else
               return (Binary_search(root->r,n));

        }
    }
}

int main()
{

    root = create_node(1);
    root->left=create_node(2);
    root->right=create_node(3);
    root->left->left=create_node(4);
    root->left->right=create_node(5);
    root->right->left=create_node(6);
    root->right->right=create_node(7);

/// BINARY TREE CREATED :-
///           1
///          / \
///         2   3
///        / \ / \
///       4  5 6  7

    printf("INORDER :");
    inorder(root);
    printf("\nPREORDER :");
    preorder(root);
    printf("\nPOSTORDER :");
    postorder(root);
    return 0;
}
