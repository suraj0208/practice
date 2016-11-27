#include <iostream>
using namespace std;

void find2missing(int arr[],int n){
    int x=0,y=0;
    int arrxor=0;
    int xor1=0;

    int max = n+2;

    switch(max%4){
        case 0:
            xor1=max;
            break;
        case 1:
            xor1=1;
            break;
        case 2:
            xor1=max+1;
            break;
        case 3:
            xor1=0;
    }

    for(int i=0;i<n;i++)
        arrxor=arrxor^arr[i];


    int xy_xor = arrxor^xor1;
    int rightmost = xy_xor & ~(xy_xor-1);


    for(int i=0;i<n;i++){
        if(arr[i] & rightmost)
            x=x^arr[i];
        else
            y=y^arr[i];
    }

    for(int i=0;i<=max;i++){
        if(i & rightmost)
            x=x^i;
        else
            y=y^i;
    }

    cout<<x<<" "<<y<<endl;



}

int main(){
    int arr[] =  { 1,2,3,5};

    int n = sizeof(arr)/sizeof(arr[0]);
    find2missing(arr,n);
}
