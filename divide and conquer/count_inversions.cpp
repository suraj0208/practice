#include <iostream>

using namespace std;

int merge(int arr[], int low,int mid,int high){

    int temp[high-low+1];

    int i=low;
    int j=mid+1;
    int k=0;

    int inversions=0;

    while(i<=mid && j<=high){
        if(arr[i]>arr[j]){
            temp[k++]=arr[j];
            j++;
            inversions+=(mid-i+1);
        }else{
            temp[k++]=arr[i];
            i++;
        }
    }

    while(i<=mid){
        temp[k++]=arr[i];
        i++;
    }

    while(j<=high){
        temp[k++]=arr[j];
        j++;
    }

    k=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[k];
        k++;
    }

    return inversions;

}

int merge_sort(int arr[],int low,int high){
    if(low>=high)
        return 0;

    int mid = (low+high)/2;

    int left=merge_sort(arr,low,mid);
    int right=merge_sort(arr,mid+1,high);

    int merge_inversions=merge(arr,low,mid,high);

    return left+right+merge_inversions;
}

int main(){
    int arr[]={ 1,20,6,4,5};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<merge_sort(arr,0,n-1)<<endl;

    return 0;

}
