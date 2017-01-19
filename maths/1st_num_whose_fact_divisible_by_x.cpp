#include <iostream>
using namespace std;

/*Given a number x, the task is to find first natural number i whose factorial is divisible by x.*/

int gcd(int a,int b){
    if(a==0)
        return b;

    if(b==0)
        return a;

    if(a>b){
        return gcd(b,a%b);
    }

    return gcd(a,b%a);
}
int find_no(int x){
    int newx=x;
    int i=1;

    for(i=1;i<x;i++){
        newx/=gcd(i,newx);

        if(newx==1)
            break;
    }

    return i;
}

int main(){
    int x=16;

    cout<<find_no(x)<<endl;

    return 0;
}
