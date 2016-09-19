#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

int mss(int a[],int n){

    if(n==1)
        return a[0];

    int m=n/2;

    int left_mss = mss(a,m);
    int right_mss = mss(a+m,n-m);

    int rightsum=INT_MIN,leftsum=INT_MIN,sum=0;

    for(int i=m;i<n;i++){
        sum=sum+a[i];
        rightsum=fmax(rightsum,sum);
    }

    sum=0;

    for(int i=m-1;i>=0;i--){
        sum=sum+a[i];
        leftsum=fmax(leftsum,sum);
    }

    int ans=leftsum+rightsum;

    return fmax(ans, fmax(left_mss,right_mss));

}

//mss o(n)

int msslogn(int a[],int n){
    int sum=0,ans=0,temp;

    for(int i=0;i<n;i++){
        temp=sum+a[i];
        if(temp>0){
            sum=temp;
        }else
            sum=0;

        ans=fmax(sum,ans);
    }
    return ans;

}

int main(){

    int a[]={3,-2,5,-1};

    cout<<mss(a,4)<<endl;

    cout<<msslogn(a,4)<<endl;

    return 0;
}
