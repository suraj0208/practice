#include <iostream>

using namespace std;

int findnonrepeating(int arr[],int low,int high){

    if(low==high){
        return arr[low];
    }

    int mid = (low+high)/2;

    if(mid&1){

        if(arr[mid]==arr[mid-1]){
            findnonrepeating(arr,mid+1,high);
        }else{
            findnonrepeating(arr,low,mid-1);
        }

    }else{

        if(arr[mid]==arr[mid+1]){
            findnonrepeating(arr,mid+2,high);
        }else{
            findnonrepeating(arr,low,mid);
        }
    }


}

int main(){
    int arr[]={ 1,1,3,3,4,4,5,5,7,7,8,8,9};

    cout<<findnonrepeating(arr,0,(sizeof(arr)/sizeof(arr[0]))-1)<<endl;

    return 0;

}
