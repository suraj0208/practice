#include <iostream>
#include <cmath>

using namespace std;

int ismul3(int n){
    if(n<0)
        return ismul3(-n);

    if(n==0)
        return 1;

    if(n<3)
        return 0;

    if(n==3)
        return 1;

    int evencount=0;
    int oddcount=0;

    while(n!=0){
        if(n&1)
            evencount++;
        n=n>>1;

        if(n&1)
            oddcount++;
        n=n>>1;
    }

    return (ismul3(abs(oddcount-evencount)));

}

int main(){

    int test;
    cin>>test;

    cout<<ismul3(test)<<endl;
}
