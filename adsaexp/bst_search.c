#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

struct node* insert(struct node* root, int value);
struct node* createNode(int value);
void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);
struct node* Search(struct node* root, int key);


void main(){

    int n;
    printf("Enter the number of elements to be inserted :");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        root=insert(root,a[i]);
    }
    printf("Preorder Traversal:");
    preorder(root);
    printf("\n");
    printf("Postorder Traversal:");
    postorder(root);
    printf("\n");
    printf("Inorder Traversal:");
    inorder(root);
    int x;
    printf("\nEnter the number to be searched:");
    scanf("%d",&x);

    if(Search(root,x)){
        printf("\nThe Given key node exists.");
    }
    else{
        printf("\nThe Given Key node doesn't exists.");
    }

}


struct node* createNode(int value){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct node* insert(struct node* root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    else{
        root->right=insert(root->right, value);
    }
    return root;

}

void preorder(struct node* root){
    if(root != NULL)
 {
 printf("%d\t", root->data);
 preorder(root->left);
 preorder(root->right);
 }
}

void inorder(struct node* root){
    if(root != NULL)
 {

 inorder(root->left);
  printf("%d\t", root->data);
 inorder(root->right);
 }
}

void postorder(struct node* root){
    if(root != NULL)
 {
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
 }
}


struct node* Search(struct node* root, int key)
{
    if(root==NULL || root->data==key){
        return root;
    }
    if(key<root->data){
        return Search(root->left,key);
    }
    else{
        return Search(root->right,key);
    }
}