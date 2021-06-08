#include<iostream>

using namespace std;

int LinearSearch(int arr[], int element, int n){
    for(int i=0; i<n; i++){
        if(arr[i]==element){
            cout<<"Element found!"<<endl;
            return 1;
        }
    }
    cout<<"Element not found!"<<endl;
    return -1;
}

int main(){
    int Myarry[7]={1, 3, 5, 6, 8, 23, 56};
    int n = sizeof(Myarry)/sizeof(Myarry[0]);
    int element=5;
    LinearSearch(Myarry, element, n);
    return 0;
}