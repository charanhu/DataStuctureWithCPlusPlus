// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Function to Merge
void merge(int arr[], int low, int mid, int high)
{
    int m = mid - low + 1;
    int n = high - mid;

    // Create temp arrays
    int A[m], B[n];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < m; i++)
        A[i] = arr[low + i];
    for (int j = 0; j < n; j++)
        B[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = low;

    while (i < m && j < n)
    {
        if (A[i] <= B[j])
        {
            arr[k++] = A[i++];
        }
        else
        {
            arr[k++] = B[j++];
        }
    }

    // Copy the remaining elements of
    // A[], if there are any
    while (i < m)
    {
        arr[k++] = A[i++];
    }

    // Copy the remaining elements of
    // B[], if there are any
    while (j < n)
    {
        arr[k++] = B[j++];
    }
}

// Function to MergeSort an array
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Driver code
int main()
{
    int arr[] = {1,4,2,5,8,1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}