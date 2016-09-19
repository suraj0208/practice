#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;

char (* ptr)(int);

int binarySeach(int arr[],int n){
    int low=0,high=n-1,result=-1;
    int mid,prev,next;

    while(low<=high){
        if(arr[low]<arr[high])
            return low;

        mid=(low+high)/2;
        next=mid+1;
        prev=(mid+n-1)%n;
        if(arr[mid]<arr[next] && arr[prev] > arr[mid])
            return mid;
        if(arr[mid]<=arr[high])      //lowest cannot exist in right half
            high=mid-1;
        else if(arr[mid]>=arr[low])  //
            low=mid+1;
    }
    return 0;
}

class A{

protected:
    virtual void test(){}

private:
    int x;
};

class B:public A{

private:
    void test(){
        x=10;
    }
};


int main(){
    int arr[]={7,8,9,1,2,3,4,5,6};
    cout<<"rotations: "<<binarySeach(arr,sizeof(arr)/sizeof(int))<<endl;


    return 0;

}
