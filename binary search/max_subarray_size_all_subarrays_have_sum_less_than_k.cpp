/*Given an array of n positive integers and a positive integer k,
the task is to find the maximum subarray size such that all subarrays of that size
have sum of elements less than k.*/

#include <iostream>
#include <cstring>
using namespace std;
int binary_search(int prefix[],int n,int k){
    int left = 1;
    int right = n;

    int ans = -1;
    int i=0;

    while(left<=right){

        int mid = (left+right)/2;

        for(i=mid;i<=n;i++){
            if(prefix[i]-prefix[i-mid]>k)
                break;
        }

        if(i==n+1){
            left=mid+1;
            ans=mid;
        }else{
            right=mid-1;
        }
    }
    return ans;
}

int cal_max(int arr[],int n,int k){
    int prefix[n+1];

    memset(prefix,0,n+1*sizeof(int));

    for(int i=0;i<n;i++)
        prefix[i+1]=prefix[i]+arr[i];

    return binary_search(prefix,n,k);
}

int main(){
    int arr[] = {1, 2, 10, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 14;
    cout << cal_max(arr, n, k) << endl;

    return 0;
}
