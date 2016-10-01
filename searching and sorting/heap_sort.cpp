#include <iostream>

using namespace std;

void heapify(int arr[],int i,int n){

    int right=2*i+2;
    int left=2*i+1;

    int max=left;

    if(right<=n){
        if(arr[right]>arr[max])
            max=right;
    }

    if(left>n)
        max=i;

    if(arr[i]<arr[max]){
        int temp=arr[max];
        arr[max]=arr[i];
        arr[i]=temp;
        heapify(arr,max,n);
    }

}

void buldHeap(int arr[],int n){
    for(int i=(n-1)/2;i>=0;i--)
        heapify(arr,i,n);
}

void heap_sort(int arr[],int n){
    buldHeap(arr,n);

    for(int i=n;i>=1;i--){
        int max=arr[0];
        arr[0]=arr[i];
        arr[i]=max;
        heapify(arr,0,i-1);
    }

}

int main(){
    int arr[] = {2,1,3,4,5,6,7,0,10};

    int n = sizeof(arr)/sizeof(arr[0]);

    heap_sort(arr,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
