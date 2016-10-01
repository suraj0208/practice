#include <iostream>

using namespace std;

void selection_sort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }

        int temp = arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

int main(){
    int arr[] = {2,1,3,4,5,6,7,0,10};

    int n = sizeof(arr)/sizeof(arr[0]);

    selection_sort(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}
