#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

int getnextpow(int n){
    int count=0;

    while(n){
        n=n>>1;
        count++;
    }

    return 1<<count;

}

int buildSegmentTreeUtil(int* seg,int arr[], int s,int e,int index){
    if(s>e)
        return INT_MAX;

    if(s==e){
        seg[index]=arr[s];
        return arr[s];
    }

    int mid = (s+e)/2;

    int left = buildSegmentTreeUtil(seg,arr,s,mid,index*2+1);
    int right = buildSegmentTreeUtil(seg,arr,mid+1,e,index*2+2);

    seg[index]=fmin(left,right);
    return seg[index];

}

int* buildSegmentTree(int arr[],int n){
    int* segtree;

    if(n&(n-1)==0)
        segtree=new int[2*n-1];
    else
        segtree=new int[2*getnextpow(n)-1];


    buildSegmentTreeUtil(segtree,arr,0,n-1,0);
    return segtree;
}

int execQ(int* seg,int ss,int se,int qs,int qe,int index){

    if(ss>=qs && se<=qe)
        return seg[index];

    if( se < qs || ss > qe )
        return INT_MAX;

    int mid = (ss+se)/2;

    int left = execQ(seg,ss,mid,qs,qe,2*index+1);
    int right = execQ(seg,mid+1,se,qs,qe,2*index+2);

    return fmin(left,right);
}


int main(){
    int arr[] = {2,5,1,4,9,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    int* segTree = buildSegmentTree(arr,n);

    cout<<execQ(segTree,0,n-1,0,3,0)<<endl;

    return 0;
}
