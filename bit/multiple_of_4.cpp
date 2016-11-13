#include <iostream>
using namespace std;

bool ismultipleof4(int n){
    if(n==1)
        return false;

    int last = n&1;
    int shifted = (n>>1);
    int second_last = shifted&1;
    int xor1=last^second_last;


    if(!last)
        xor1 = xor1|(shifted<<1);

    if(xor1==n)
        return true;
    else
        return false;

}

int main(){
    int n=1024;
    cout<<ismultipleof4(n)<<endl;

    return 0;
}
