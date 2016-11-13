#include <iostream>

using namespace std;

int multiplywith10(int n){
    /*
        n*10 = n*(2+8)
             = n*2 + n*8
    */

    return (n<<1) + (n<<3);
}

int main(){
    int n=16;

    cout<<multiplywith10(n)<<endl;

    return 0;
}
