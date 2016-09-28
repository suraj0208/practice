#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int max_subarray(int arr[],int n){
    int prev=INT_MIN;
    int ans=INT_MIN;


    for(int start=0;start<n;start++){
        prev=0;

        for(int end=start;end<n;end++){
            ans=max(ans,prev+arr[end]);
            prev+=arr[end];
        }

    }

    return ans;

}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<max_subarray(arr,n)<<endl;


    return 0;
}
