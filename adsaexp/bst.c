#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
} *root = NULL;

void main(){

}

/*void insert(int n){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* parent;
    struct node* current;
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
    
    if(root=NULL){
        root=temp;
    }

    else{

    }

}*/

struct node* createNode(int value){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}