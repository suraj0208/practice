#include <iostream>
using namespace std;

unsigned int mod(int n){
    int mask = n >> ( sizeof(int)*8 -1 );

    n=n+mask;
    return n^mask;

}

int main(){
    int n = -10;

    cout<<mod(n)<<endl;

}
