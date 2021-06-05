   #include<iostream>
   
   using namespace std;
   
   void display(int arr[], int n){
       //Code for traversal
       cout<<"Present array elements ";
       for (int i = 0; i < n; i++)
       {
           cout<<arr[i]<<" ";
       }
       cout<<endl;
       
   }

int indDeletion(int arr[], int size, int index){
    //Code for Deletion
    cout<<"Deleted element is "<<arr[index]<<endl;
    for (int i = index; i <size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    return 1;
}

   
   int main(){
       int arr[100]={7, 8, 12, 27, 88};
       int size=5, element=45, index=2;
       display(arr, size);
       //Insertion
       indDeletion(arr, size, index);
       size-=1; //Decrese the size
       display(arr, size);
       return 0;
   }