#include <iostream>
#include <cmath>

using namespace std;

int median(int arr[],int n){
    if(n&1){
        return arr[n/2];
    }

    return (arr[n/2]+arr[n/2-1])/2;

}

int getmedian(int arr1[],int arr2[],int n){
    if(n==1)
        return arr1[0];

    if(n==2)
        return (fmax(arr1[0],arr2[0])+fmin(arr1[1],arr2[1]))/2;

    int m1 = median(arr1,n);
    int m2 = median(arr2,n);

    if(m1==m2)
        return m1;

    if(m1>m2){
        if(n%2==0){
            return getmedian(arr1,arr2+n/2-1,n-n/2+1);
        }
        return getmedian(arr1,arr2+n/2,n-n/2);

    }

    if(n%2==0)
        return getmedian(arr1+n/2-1,arr2,n-n/2+1);

    return getmedian(arr1+n/2,arr2,n-n/2);



}


int main(){
    int arr1[]={1,2,3,6};
    int arr2[]={ 4,6,8,10 };

    int n = sizeof(arr1)/sizeof(arr1[0]);

    cout<<getmedian(arr1,arr2,n)<<endl;


    return 0;

}
