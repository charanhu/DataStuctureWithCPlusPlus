#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            //Swap the A[i] with A[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] that is pivote with A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition
    //Atleast two elements present enter to array else not enters
    if (low < high)
    {
        partitionIndex = partition(A, low, high); //the permanent location of Array[partitionIndex] in that array
        quickSort(A, low, partitionIndex - 1);    // sort left subarray
        quickSort(A, partitionIndex + 1, high);   // sort right subarray
    }
}

int main()
{
    int A[] = {4, 4, 3, 8, 7, 5, 4};
    int n;
    n = 7;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}