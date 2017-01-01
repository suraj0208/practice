#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n=8;
    int k=6;

    if(k>n){
        cout<<n*(n+1)/2<<endl;
    }else{
        int m = n%k;

        cout<<(n/k)*k*(k-1)/2 + m*(m+1)/2<<endl;
    }

    return 0;
}
