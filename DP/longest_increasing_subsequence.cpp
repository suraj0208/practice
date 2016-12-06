#include <iostream>
#include <cmath>

using namespace std;

int lis(int arr[],int n){
    int lisarr[n];

    for(int i=0;i<n;i++)
        lisarr[i]=1;


    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                lisarr[i]=fmax(lisarr[j]+1,lisarr[i]);
            }
        }
    }

    int max=1;

    for(int i=0;i<n;i++){
        if(lisarr[i]>max)
            max=lisarr[i];
    }

    return max;

}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<lis(arr,n)<<endl;

}
