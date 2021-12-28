#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL, *cur, *temp;
struct node* create(){
    cur = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &cur->data);
    cur->left = NULL;
    cur->right = NULL;
    if(root == NULL){
        root = cur;
    }
    else{
        temp = root;
        while(temp != NULL){
            if(cur->data < temp->data && temp->left == NULL){
                temp->left = cur;
                return root;
            }
            else if(cur->data < temp->data && temp->left != NULL){
                temp = temp->left;
            }
            else if(cur->data > temp->data && temp->right == NULL){
                temp->right = cur;
                return root;
            }
            else{
                temp = temp->right;
            }
        }
    }
}

//Pre order
void preorder(struct node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//inorder
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
//post order
void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    int ch, ele;
    while(1){
        printf("1-Create\n2-Preorder\n3-Inorder\n4-Postorder\n5-Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                root = create();
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                exit(0);
        }
    }
}

