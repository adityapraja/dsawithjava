#include<stdio.h>
#include<stdlib.h>

struct node             //creation of struc node
{
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;
//functions definations
struct node* insert(struct node* root, int value);
struct node* createNode(int value);
void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);


void main()
{
    int n;
    printf("Enter the number of elements to be inserted :");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        root=insert(root,a[i]);         //insertion of elements in bst
    }
    printf("Preorder Traversal:");      //traversals
    preorder(root);
    printf("\n");

    printf("Postorder Traversal:");
    postorder(root);
    printf("\n");

    printf("Inorder Traversal:");
    inorder(root);
    printf("\n");
}

struct node* createNode(int value)          //creates the node if node doesnt exists
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct node* insert(struct node* root, int value)
{
    if(root == NULL)                //inserts based on condition of binary properties
    {
        return createNode(value);
    }
    if(value<root->data)
    {
        root->left=insert(root->left,value);
    }
    else
    {
        root->right=insert(root->right, value);
    }
    return root;

}

void preorder(struct node* root)        //preorder traversal Root-L-R
{   
    if(root != NULL)
    {
    printf("\t%d", root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void inorder(struct node* root)     //inorder traversal L-Root-R
{
    if(root != NULL)
    {
    inorder(root->left);
    printf("\t%d", root->data);
    inorder(root->right);
    }
}

void postorder(struct node* root)       //postorder traversal L-R-Root
{
    if(root != NULL)
    {
    postorder(root->left);
    postorder(root->right);
    printf("\t%d", root->data);
    }
}