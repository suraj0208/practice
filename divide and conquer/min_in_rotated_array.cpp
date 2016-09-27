#include <iostream>

using namespace std;

int find_min(int arr[],int low,int high){

    if(low>high)
        return -1;

    int mid = (low+high)/2;

    int n=high-low+1;
    int prev = (mid-1+n)%n;
    int next = (mid+1)%n;

    if( arr[prev] > arr[mid] && arr[mid] < arr[next] )
        return arr[mid];

    if(arr[mid]<arr[high])
        return find_min(arr,low,mid-1);

    find_min(arr,mid+1,high);

}

int main(){
    int arr[]={ 8,10,12,14,2,4 };

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<find_min(arr,0,n-1)<<endl;

    return 0;

}
