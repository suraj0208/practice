#include <iostream>

using namespace std;

void heapify(int arr[],int i,int n){
    int l=i*2;
    int r=i*2+1;

    int max=l;

    if(l>=n)
        return;

    if(r<n){
        if(arr[l]<arr[r])
            max=r;
    }

    if(arr[i]<arr[max]){
        int temp=arr[max];
        arr[max]=arr[i];
        arr[i]=temp;
        heapify(arr,max,n);
    }
}

void buildHeap(int arr[], int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,i,n);
    }

    for(int i=n-1;i>=1;i--){
        int temp=arr[1];
        arr[1]=arr[i];
        arr[i]=temp;
        heapify(arr,1,i);
    }
}

int main(){
    int arr[]= {0,6,3,2,1,5,7,4,10};

    int n=sizeof(arr)/sizeof(int);

    cout<<n<<endl;

    buildHeap(arr,n);

    for(int i=1;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;


    return 0;
}
