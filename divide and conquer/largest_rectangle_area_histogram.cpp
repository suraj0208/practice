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

int getMin(int arr[],int i,int j){
    if(i==INT_MAX)
        return j;
    if(j==INT_MAX)
        return i;

    return arr[i]>arr[j]?j:i;
}

int buildSegmentTreeUtil(int* seg,int arr[], int s,int e,int index){
    if(s>e)
        return INT_MAX;

    if(s==e){
        seg[index]=s;
        return s;
    }

    int mid = (s+e)/2;

    int left = buildSegmentTreeUtil(seg,arr,s,mid,index*2+1);
    int right = buildSegmentTreeUtil(seg,arr,mid+1,e,index*2+2);

    seg[index]=getMin(arr,left,right);
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

int execQ(int* seg,int arr[],int ss,int se,int qs,int qe,int index){

    if(ss>=qs && se<=qe)
        return seg[index];

    if( se < qs || ss > qe )
        return INT_MAX;

    int mid = (ss+se)/2;

    int left = execQ(seg,arr,ss,mid,qs,qe,2*index+1);
    int right = execQ(seg,arr,mid+1,se,qs,qe,2*index+2);

    return getMin(arr,left,right);
}

int largestArea(int hist[],int* seg,int n,int low,int high){
    if(low>high)
        return INT_MIN;

    if(low==high)
        return hist[low];

    int min = execQ(seg,hist,0,n,low,high,0);

    int left = largestArea(hist,seg,n,low,min-1);
    int right = largestArea(hist,seg,n,min+1,high);

    return fmax((high-low+1)*hist[min], fmax(left,right));

}

int main(){
    int arr[] = {6,1,5,4,5,2,6};

    int n = sizeof(arr)/sizeof(arr[0]);

    int* segTree = buildSegmentTree(arr,n);

    cout<<largestArea(arr,segTree,n-1,0,n-1)<<endl;

    return 0;
}
