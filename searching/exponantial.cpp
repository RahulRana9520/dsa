#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{
    while(low<=high)
    {
        int mid = (low+high)/2;

        if(arr[mid]==key)
            return mid;

        else if(arr[mid]<key)
            low = mid+1;

        else
            high = mid-1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int key)
{
    if(arr[0]==key)
        return 0;

    int i = 1;

    while(i<n && arr[i]<=key)
        i = i*2;

    return binarySearch(arr,i/2,min(i,n-1),key);
}

int main()
{
    int n,key;

    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter sorted array elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter element to search: ";
    cin>>key;

    int result = exponentialSearch(arr,n,key);

    if(result!=-1)
        cout<<"Element found at index "<<result<<endl;
    else
        cout<<"Element not found"<<endl;

    return 0;
}