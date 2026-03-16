#include <iostream>
using namespace std;

//as the name suggest it work like real bubble , first j triverse to n-i-1 and after i increase the last of j decreasing like bubble 
void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
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
    bubbleSort(arr,n);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}