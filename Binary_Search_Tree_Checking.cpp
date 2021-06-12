#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * CreateNode(int data){
    struct Node* newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;//assign  data
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

int isBST(struct Node * root){
    static struct Node* prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && (root->data) <= (prev->data)){
            return 0;
        }
        prev=root;
        return isBST(root->right);

    }
    else{
        return 1;
    }
}

int main(){
    struct Node* p=CreateNode(5);
    struct Node* p1=CreateNode(3);
    struct Node* p2=CreateNode(6);
    struct Node* p3=CreateNode(1);
    struct Node* p4=CreateNode(4);

                //     5
                //    / \
                //   3   6
                //  / \
                // 1   4
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    Inorder(p);
    cout<<" "<<endl;
    if(isBST(p)){
        cout<<"Tree is BST"<<endl;
    }
    else{
        cout<<"Tree is NOT BST"<<endl;
    }
    return 0;
}