#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};


//Creating Node
struct Node * CreateNode(int data){
    struct Node* newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;//assign  data
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}


//Inorder traversal
void Inorder(struct Node * root){
    if(root!=NULL){
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}


//Cheching BST 
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


//Searching Founction
struct Node * searchKey(struct Node * root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key< root->data){
        return searchKey(root->left, key);
    }
    else{
        return searchKey(root->right, key);
    }
}

int main(){

    // Creating the Nodes
    struct Node* p=CreateNode(5);
    struct Node* p1=CreateNode(3);
    struct Node* p2=CreateNode(6);
    struct Node* p3=CreateNode(1);
    struct Node* p4=CreateNode(4);


//DEMo  bST
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

//Checking BST 
    if(isBST(p)){
        cout<<"Tree is BST"<<endl;
    }
    else{
        cout<<"Tree is NOT BST"<<endl;
    }


//Searching for BST
    if(searchKey(p, 7)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}