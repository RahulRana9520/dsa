#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n)
{
    vector<float> bucket[n];

    for(int i=0;i<n;i++)
    {
        int index = n*arr[i];
        bucket[index].push_back(arr[i]);
    }

    for(int i=0;i<n;i++)
        sort(bucket[i].begin(),bucket[i].end());

    int k=0;

    for(int i=0;i<n;i++)
        for(float x : bucket[i])
            arr[k++] = x;
}

int main()
{
    int n;

    cout<<"Enter size of array: ";
    cin>>n;

    float arr[n];

    cout<<"Enter elements (0 to 1 range):\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    bucketSort(arr,n);

    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}