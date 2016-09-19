#include<iostream>

using namespace std;

int binarySeach(int arr[],int n, int x){
    int low=0,high=n-1;
    int mid;

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]==x)
            return mid;

        if(arr[mid]>x)
            high=mid-1;
        else
            low=mid+1;
    }

    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};

    int x;
    cin>>x;

    int loc=binarySeach(arr,sizeof(arr)/sizeof(int),x);
    cout<<loc<<endl;



}
