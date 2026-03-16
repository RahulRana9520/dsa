#include <iostream>
using namespace std;

//it is called inserting because we select one element and sort it with all previous elements 
void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main()
{
    int n;

    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter array elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    insertionSort(arr,n);

    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}