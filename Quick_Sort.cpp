#include<iostream>


using namespace std;

void PrintArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<" "<<endl;
}

int PartitionArray(int *A, int low, int high){
    int pivote=A[low];
    int i=low;
    int j=high;
    int temp;
    do{
        while(A[i]<=pivote){
            i++;
        }
        while(A[j]>=pivote){
            j--;
        }
        if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}


void QuickASort(int *A, int low, int high){
    int j;
    if(low<high){  
        j=PartitionArray(A, low, high);
        QuickASort(A, low, j-1);
        QuickASort(A, j+1, high);
    }
}



int main(){
int A[6]={4, 1, 3, 78, 4, 4};
int n=6;
PrintArray(A, 6);

QuickASort(A, 0, n-1);
cout<<"After sorting"<<endl;
PrintArray(A, 6);

return 0;
}