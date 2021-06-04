#include<iostream>

using namespace std;

class myArray{
    public:
        int total_size;
        int used_size;
        int *ptr;
};

void createArray(myArray * a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = new int[sizeof(int)];

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = new int[sizeof(int)];

}

void show(myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        cout<<" "<<(a->ptr)[i]<<endl;
    }
    
}

void setVal(myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        cout<<"Enter Marks"<<endl;
        cin>>n;
        (a->ptr)[i]=n;

    }
    
}

int main(){
    myArray marks;
    int Tsize, Usize;
    cout<<"Enter total memory size"<<endl;
    cin>>Tsize;
    cout<<"Enter used memory size"<<endl;
    cin>>Usize;
    createArray(&marks, Tsize, Usize);
    cout<<"We are running setVal"<<endl;
    setVal(&marks);
    cout<<"We are running show"<<endl;
    show(&marks);
    return 0;
}