#include <iostream>

using namespace std;

int getindex(int arr[],int low,int high,int x,bool lowOrHigh){

    int mid;
    int found=-1;

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]==x){
            found=mid;

            if(lowOrHigh)
               high=mid-1;
            else
               low=mid+1;

        }else if(arr[mid]>x){
            high=mid-1;
        }else
            low=mid+1;

    }

    return found;

}

int main(){
    int arr[]={ 1,1,2,2,2,2,3 };

    int n = sizeof(arr)/sizeof(arr[0]);

    int x=2;
    cout<<getindex(arr,0,n-1,x,false)-getindex(arr,0,n-1,x,true)+1<<endl;

    return 0;

}
