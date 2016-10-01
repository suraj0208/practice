#include <iostream>

using namespace std;

void insertion_sort(int arr[],int n){
    int i;

    for(int i=1;i<n;i++){
        int j=i-1;

        int temp = arr[i];

        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        };

        arr[j+1]=temp;

    }
}

int main(){
    int arr[] = {2,1,3,4,5,6,7,0,10};

    int n = sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}
