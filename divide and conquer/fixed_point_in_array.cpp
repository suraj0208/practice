#include <iostream>

using namespace std;

int find_fixed(int arr[],int low,int high){
    if(low>high)
        return -1;

    int mid = (low+high)/2;

    if(arr[mid]==mid)
        return arr[mid];

    if(mid>arr[mid])
        return find_fixed(arr,mid+1,high);

    return find_fixed(arr,low,mid-1);


}

int main(){
    int arr[]={-10,-5,3,4,7,9 };

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<find_fixed(arr,0,n-1)<<endl;

    return 0;

}
