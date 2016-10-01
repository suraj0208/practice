#include <iostream>

using namespace std;

void merge(int arr[],int low,int mid,int high){

    int temp[high-low+1];

    int i=low;
    int j=mid+1;
    int k=0;

    while(i<=mid && j<=high){
        if(arr[i]>arr[j]){
            temp[k++]=arr[j];
            j++;
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

    for(i=low;i<=high;i++){
        arr[i]=temp[k];
        k++;
    }
}

void merge_sort(int arr[],int low,int high){

    if(low>=high)
        return;

    int mid = (low+high)/2;

    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);

    merge(arr,low,mid,high);

}

int main(){
    int arr[] = {2,1,3,4,5,6,7,0,10};

    int n = sizeof(arr)/sizeof(arr[0]);

    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}
