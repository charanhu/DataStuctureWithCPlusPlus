#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * CreateNode(int data){
    struct Node* newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void Inorder(struct Node * root){
    if(root!=NULL){
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}

int main(){
    struct Node* p=CreateNode(5);
    struct Node* p1=CreateNode(3);
    struct Node* p2=CreateNode(6);
    struct Node* p3=CreateNode(1);
    struct Node* p4=CreateNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    Inorder(p);
    return 0;
}