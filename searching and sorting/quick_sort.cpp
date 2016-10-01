#include <iostream>

using namespace std;

int partition(int arr[],int low,int high){
    int i=low+1;
    int j=high;

    int pivot = arr[low];

    while(i<=j){

        while(i<=high && arr[i]<pivot)
            i++;

        while(j>=low && arr[j]>pivot)
            j--;

        if(i>j)
            break;

        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    arr[low]=arr[j];
    arr[j]=pivot;
    return j;

}


void quick_sort(int arr[],int low,int high){
    if(low>=high)
        return;

    int p =partition(arr,low,high);

    quick_sort(arr,low,p);

    quick_sort(arr,p+1,high);

}

int main(){
    int arr[] = {5,2,1,3,4,6,7,0,10};

    int n = sizeof(arr)/sizeof(arr[0]);

    quick_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}
