#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node * head=NULL;


void InsertAtBegining(int data){
    struct Node * newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(head==NULL){
        head=newNode;
        newNode->next=NULL;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}

void InsertAtEnd(int data){
    struct Node * newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    struct Node * ptr=head;
    if(head==NULL){
        head=newNode;
        newNode->next=NULL;
    }
    else{ 
        while(ptr->next!=NULL){
            ptr=ptr->next;
            if(ptr->next==NULL){
                ptr->next=newNode;
                newNode->next=NULL;
            }
        }
        
    }
}

void InsertAtIndex(int data, int index){
    struct Node * newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    struct Node * ptr=head;
    int i=0;
    while(i!=index-1){
        ptr=ptr->next;
        i++;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;

}

void InsertAtMiddle(int data, int element){
    struct Node * newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    struct Node * ptr=head;
    while(ptr->data!=element){
        ptr=ptr->next;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;

}

void DeleteFront(){
    struct Node * ptr=head;
    if(head!=NULL){
        head=ptr->next;
    }
    free(ptr);
    
}

void DeleteEnd(){
    struct Node * ptr=head;
    struct Node * qtr=head->next;
    while(qtr->next!=NULL){
        ptr=ptr->next;
        qtr=qtr->next;
    }
    ptr->next=NULL;
    free(qtr);
    
}


void display(){
    struct Node * ptr=head;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
    
}



int main(){
    cout<<"Beginning"<<endl;
    InsertAtBegining(10);
    InsertAtBegining(20);
    InsertAtBegining(30);
    display();
    cout<<"End"<<endl;
    InsertAtEnd(70);
    InsertAtEnd(70);
    display();
    cout<<"Index"<<endl;
    InsertAtIndex(25, 5);
    display();
    cout<<"Middle"<<endl;
    InsertAtMiddle(35,30);
    display();
    cout<<"Delete Front"<<endl;
    DeleteFront();
    display();
    cout<<"Delete End"<<endl;
    DeleteEnd();
    display();
    return 0;
}