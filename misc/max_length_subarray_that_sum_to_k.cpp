#include <iostream>
#include <cmath>

using namespace std;

//Question asked in Veritas :D

int getMaxLengthSubArray(int arr[],int n,int k){
    int max=-1;

    int i=0;
    int j=0;

    int running_sum=0;

    while(i<n && j < n){
        while(j<n && running_sum+arr[j]<=k){
            running_sum+=arr[j];
            j++;
        }

        if(running_sum==k){
            max=fmax(max,j-i);
            j++;
            i=j;
            running_sum=0;
        }

        while(i<n && running_sum+arr[j]>k){
            running_sum-=arr[i];
            i++;
        }
    }

    return max;

}


int main(){
    int arr[] = {1,2,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<getMaxLengthSubArray(arr,n,7)<<endl;



    return 0;
}
