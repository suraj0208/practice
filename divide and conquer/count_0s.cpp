#include <iostream>

using namespace std;

int find_0s(int arr[],int low,int high){
    if(low>high)
        return -1;

    if(arr[low]==arr[high] && arr[low]==0){
        return high-low+1;
    }else if(arr[low]==arr[high] && arr[low]==1)
        return 0;

    int mid = (low+high)/2;


    return find_0s(arr,low,mid) + find_0s(arr,mid+1,high);



}

int main(){
    int arr[]={1, 0,0, 0, 0, 0, 0, 0};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<find_0s(arr,0,n-1)<<endl;

    return 0;

}
