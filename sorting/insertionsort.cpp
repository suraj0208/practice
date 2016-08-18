#include <iostream>

using namespace std;

int main(){
    int arr[] = {5,1,3,2,6,7,10,9};

    // 1 3 5 2 6 7 10 9
    int n= sizeof(arr)/sizeof(int);

    for(int i=1;i<n;i++){
        int j=i-1;
        int temp=arr[i];

        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=temp;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
