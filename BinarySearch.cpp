#include<iostream>
#include<array>

using namespace std;

int BinarySearch(int arr[], int element, int n){
    int low=0;
    int high=n-1;
    
    //Check whether low is less than high
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==element){
            cout<<"Success"<<endl;
            return 1;
        }
        if(element<arr[mid]){
            high=mid-1;
        }
        if(element>arr[mid]){
            low=mid+1;
        }
    }
    cout<<"Element not found"<<endl;
    return -1;
}

int main(){
    int Myarry[7]={1, 3, 5, 6, 8, 23, 56};
    int n = sizeof(Myarry)/sizeof(Myarry[0]);
    int ele=1;
    BinarySearch(Myarry, ele, n);
    return 0;
}