#include <iostream>
#include <climits>
using namespace std;

struct minmax{
    int min;
    int max;
};

minmax findminmax(int arr[],int low,int high){
    minmax temp;

    if(low>high){
        temp.max=INT_MIN;
        temp.min=INT_MAX;
        return temp;
    }

    if(low==high){
        temp.max=arr[low];
        temp.min=arr[low];
        return temp;
    }

    if(low+1==high){
        if(arr[low]>arr[high]){
            temp.max=arr[low];
            temp.min=arr[high];
        }else{
            temp.max=arr[high];
            temp.min=arr[low];
        }
        return temp;
    }

    int mid = (low+high)/2;

    minmax left = findminmax(arr,low,mid);
    minmax right = findminmax(arr,mid+1,high);

    if(left.max>right.max)
        temp.max=left.max;
    else
        temp.max=right.max;

    if(left.min<right.min)
        temp.min=left.min;
    else
        temp.min=right.min;

    return temp;
}


int main(){
    int arr[]={ 1000,11,445,1,330,3000 };

    int n = sizeof(arr)/sizeof(arr[0]);

    minmax mm = findminmax(arr,0,n-1);

    cout<<mm.max<<" "<<mm.min<<endl;
    return 0;

}
