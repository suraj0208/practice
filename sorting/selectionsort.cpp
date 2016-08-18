#include <iostream>

using namespace std;

int main(){
    int arr[]={2,1,5,3,7,6,10,9};

    int n = sizeof(arr)/sizeof(int);

    for(int i=0;i<n-1;i++){
        int smallest=i ;
        for(int j=i;j<n;j++){
            if(arr[smallest]>arr[j])
                smallest=j;

        }
        int temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=temp;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}
