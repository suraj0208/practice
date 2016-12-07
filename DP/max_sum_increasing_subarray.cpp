#include <iostream>
#include <cmath>

using namespace std;
//arr is array of positive integers

int max_sum_increasing_subarray(int arr[],int n){
    int max = 0;
    int curr = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i-1]<arr[i])
            curr=curr+arr[i];
        else{
            max=fmax(max,curr);
            curr=arr[i];
        }

    }
    return curr;

}

int main(){
    int arr[] = {1,2,2,4};


    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<max_sum_increasing_subarray(arr,n)<<endl;

}
