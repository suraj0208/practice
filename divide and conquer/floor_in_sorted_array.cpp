#include <iostream>

using namespace std;

int findFloor(int arr[],int low,int high,int x){

    int mid = (low+high)/2;

    if(low>high)
        return -1;

    if(x>=arr[high])
        return arr[high];

    if(arr[mid]==x)
        return arr[mid];

    if(mid>0 && x > arr[mid-1] && x < arr[mid])
        return arr[mid-1];

    if(x<arr[mid])
        return findFloor(arr,low,mid-1,x);

    return findFloor(arr,mid+1,high,x);

}

int main(){
    int arr[]={ 1,2,8,10,10,12,19 };

    cout<<findFloor(arr,0,(sizeof(arr)/sizeof(arr[0]))-1,5)<<endl;
    cout<<findFloor(arr,0,(sizeof(arr)/sizeof(arr[0]))-1,20)<<endl;
    cout<<findFloor(arr,0,(sizeof(arr)/sizeof(arr[0]))-1,0)<<endl;

    return 0;

}
