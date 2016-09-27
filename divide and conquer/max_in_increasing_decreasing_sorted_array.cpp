#include <iostream>

using namespace std;


int find_max(int arr[],int low,int high){
    if(low>high)
        return -1;

    if(low==high)
        return arr[low];

    if(high==low+1){
        if(arr[low]>arr[high])
            return arr[low];
        else
            return arr[high];
    }

    int mid = (low+high)/2;

    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        return arr[mid];

    if(arr[mid-1]<arr[mid])
        return find_max(arr,mid,high);

    return find_max(arr,low,mid);

}


int main(){
    //int arr[] = {8,10,20,80,100,200,400,500,3,2,1};

    //int arr[] = {1,3,50,10,9,7,6};

    //int arr[] = {10,20,30,40,50};

    //int arr[] = {120,100,80,20,0};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<find_max(arr,0,n-1)<<endl;

    return 0;

}
