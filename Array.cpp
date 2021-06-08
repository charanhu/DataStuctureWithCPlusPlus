   #include<iostream>
   
   using namespace std;
   
   void display(int arr[], int n){
       //Code for traversal
       for (int i = 0; i < n; i++)
       {
           cout<<arr[i]<<" ";
       }
       cout<<endl;
       
   }

int indInsertion(int arr[], int size, int element, int capacity, int index){
    //Code for insertion
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
    
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
        int n, arr[n], choice, element, index;
        int size= sizeof(arr)/sizeof(arr[0]);
        cout<<"Enter array capacity"<<endl;
        cin>>n;
        // cout<<"Enter array elements"<<endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>arr[i];
        // }
        while(1){
            cout<<"Enter your choice"<<endl;
            cout<<"1. Insertion"<<endl;
            cout<<"2. Deletion"<<endl;
            cout<<"3. Display"<<endl;
            cout<<"4. Exit"<<endl;
            switch (choice)
            {
            case 1:
                cout<<"Enter elemnt to be inserted"<<endl;
                cin>>element;
                cout<<"Enter Position to insert Element"<<endl;
                cin>>index;
                indInsertion(arr, size, element, n, index);
                break;

            case 2:
                cout<<"Enter Position to Delete Element"<<endl;
                cin>>index;
                indDeletion(arr, size, index);
                break;

            case 3:
                display(arr, size);
            
            default:
                exit(0);
            }

        }

       return 0;
   }