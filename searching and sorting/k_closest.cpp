#include <iostream>
#include <climits>

using namespace std;

int binary_search(int arr[],int low,int high,int x){
    if(low>high)
        return -1;

    int mid = (low+high)/2;

    if(arr[mid]==x)
        return mid;

    if(arr[mid]>x)
        return binary_search(arr,low,mid-1,x);

    return binary_search(arr,mid+1,high,x);

}

void k_closest(int arr[],int n,int k,int x){
    int index = binary_search(arr,0,n-1,x);

    int r = index+1;

    int l = index-1;


    for(int i=0;i<k;i++){

        if(l>=0 && x-arr[l]<arr[r]-x){
            cout<<arr[l]<<" ";
            l--;
        }else if (r<n){
            cout<<arr[r]<<" ";
            r++;
        }

    }

}

int main(){
    int arr[] = {12, 16, 22, 30, 35, 39, 42,
                 45, 48, 50, 53, 55, 56};

    int n = sizeof(arr)/sizeof(arr[0]);

    k_closest(arr,n,4,35);

    cout<<endl;

    return 0;
}
