#include <iostream>
#include <climits>

using namespace std;

int min_length_unsorted(int arr[],int n){

    int i=0;
    int j=n-1;

    for(;i<n-1;i++){
        if(arr[i]>arr[i+1])
            break;
    }

    for(;j>0;j--)
        if(arr[j]<arr[j-1])
            break;

    if(i>j)
        return -1;

    int min=INT_MAX;
    int max=INT_MIN;

    for(int k=i;k<=j;k++){
        if(arr[k]>max)
            max=arr[k];

        else
            if(arr[k]<min)
                min=arr[k];

    }

    for(int k=0;k<i;k++){
        if(arr[k]>min){
            i=k;
            break;
        }
    }

    for(int k=n-1;k>j;k--){
        if(arr[k]<max){
            j=k;
            break;
        }
    }

    cout<<i<<" "<<j<<endl;

    return j-i+1;


}

int main(){
    int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};

    int n = sizeof(arr)/sizeof(arr[0]);


    cout<<min_length_unsorted(arr,n);

    cout<<endl;

    return 0;
}
