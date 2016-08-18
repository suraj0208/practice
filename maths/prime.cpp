#include <iostream>

using namespace std;

bool isPrime(int n){

    if(n%2==0)
        return false;

    if(n%3==0)
        return false;

    int i=5;
    int w=2;

    while(i*i<=n){
        if(n%i==0)
            return false;

        i=i+w;
        w=6-w;
    }

    return true;
}

int main(){

    int n;
    cin>>n;
    cout<<isPrime(n)<<endl;

    return 0;
}
