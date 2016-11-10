#include <iostream>

using namespace std;

/*
 * Given a positive integer n, find count of positive integers i such that 0 <= i <= n and n+i = n^i
 * */

int getnumpair(int n){
    int unset = 0;

    while(n>0){
        if(!(n&1))
            unset++;
        n=n>>1;
    }

    return 1<<unset;

}

int main(){
    int n=7;

    cout<<getnumpair(n)<<endl;



    return 0;
}
