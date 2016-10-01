#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void closest_pair(int arr[],int n,int x){
    int i=0;
    int j=n-1;

    int diff=INT_MAX;
    int res_l=-1,res_r=-1;

    while(i<j){
        if(abs(x-(arr[j]+arr[i]))<diff){
            diff=abs(x-(arr[j]+arr[i]));
            res_l=i;
            res_r=j;
        }

        if(arr[i]+arr[j]<x)
            i++;
        else
            j--;
    }
    cout<<arr[res_l]<<" "<<arr[res_r];
}

int main(){
    int arr[] = {10, 22, 28, 29, 30, 40};

    int n = sizeof(arr)/sizeof(arr[0]);

    closest_pair(arr,n,54);

    cout<<endl;

    return 0;
}
