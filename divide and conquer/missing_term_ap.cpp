#include <iostream>

using namespace std;

int find_missing_term(int arr[],int low,int high,int diff){

    if(low>high)
        return -1;

    int mid = (low+high)/2;

    if(arr[mid+1]-arr[mid]!=diff)
        return arr[mid]+diff;

    if(arr[mid]-arr[mid-1]!=diff)
        return arr[mid-1]+diff;

    if(arr[mid]==arr[0]+mid*diff)
        return find_missing_term(arr,mid+1,high,diff);

    return find_missing_term(arr,low,mid-1,diff);
}

int main(){
    int arr[]={ 2,4,8,10,12,14 };

    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = (arr[n-1]-arr[0])/n;

    cout<<find_missing_term(arr,0,n-1,diff)<<endl;

    return 0;

}
