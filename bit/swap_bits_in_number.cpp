#include <iostream>
using namespace std;

#define uint unsigned int

uint swapBits(uint n, uint l,uint r,uint k){
    uint right=n;
    uint left =n;

    uint pattern = 1<<k;
    pattern-=1;

    right = right>>r & pattern;
    left=left>>l & (pattern);

    uint xor1 = left^right;

    n=n^(xor1<<l);
    n=n^(xor1<<r);

    return n;
}

int main(){
    uint n = 47;
    uint k=3;
    uint l=5;
    uint r=1;

    cout<<swapBits(n,l,r,k)<<endl;

    return 0;
}
