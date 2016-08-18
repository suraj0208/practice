#include <iostream>

using namespace std;

int main(){
    int arr[] = {6,4,2,1,8,3,10};
    int n=sizeof(arr)/sizeof(int);

    for(int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
