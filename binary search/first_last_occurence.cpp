#include<iostream>
#include<stdio.h>
using namespace std;

int binarySeach(int arr[],int n, int x, bool forl){
    int low=0,high=n-1,result=-1;
    int mid;

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]==x){
            result=mid;

            if(forl)        //find first occurence
                high=mid-1;
            else
                low=mid+1;
        }else if(arr[mid]>x)
            high=mid-1;
        else
            low=mid+1;
    }

    return result;
}

int main(){
    int arr[]={1,2,3,3,3,3,3,8,9};

    int x;
    cin>>x;

    int first=binarySeach(arr,sizeof(arr)/sizeof(int),x,true);
    int last=binarySeach(arr,sizeof(arr)/sizeof(int),x,false);



    cout<<"first: "<<first<<" last: "<<last<<endl;

}
