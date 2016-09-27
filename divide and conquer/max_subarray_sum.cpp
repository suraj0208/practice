#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int maxCrossingSum(int arr[],int low, int mid,int high){

    int left=INT_MIN;
    int sum=0;

    for(int i=mid;i>=low;i--){
        sum+=arr[i];

        if(sum>left)
            left=sum;

    }

    int right=INT_MIN;
    sum=0;

    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];

        if(sum>right)
            right=sum;
    }

    return left+right;

}

int max_subarray(int arr[],int low,int high){
    if(low>high)
        return INT_MIN;

    if(low==high)
        return arr[low];

    int mid =(low+high)/2;

    int left=max_subarray(arr,low,mid-1);
    int right=max_subarray(arr,mid+1,high);

    int inmid = maxCrossingSum(arr,low,mid,high);

    return fmax(inmid,fmax(left,right));

}

int main(){
    int arr[] = {-2,-5,6,-2,-3,1,5,-6};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<max_subarray(arr,0,n-1)<<endl;


    return 0;
}
