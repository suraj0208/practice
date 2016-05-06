#include<iostream>
#include<stdio.h>
using namespace std;

int binarySeach(int arr[],int n,int x){
    int low=0,high=n-1;
    int mid,prev,next;

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]==x)
            return mid;

        else if(arr[mid]<=arr[high]){
            if(x>arr[mid] && x <=arr[high])
                low=mid+1;
            else
                high=mid-1;

        }else{
            if(x>=arr[low] && x<arr[mid])
                high=mid-1;
            else
                low=mid+1;
        }

    }
    return -1;
}

int main(){
    int arr[]={7,8,9,1,2,3,4,5,6};

    int x;
    cin>>x;
    cout<<"rotations: "<<binarySeach(arr,sizeof(arr)/sizeof(int),x)<<endl;

}
