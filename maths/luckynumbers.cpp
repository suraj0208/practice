#include <iostream>
using namespace std;

int islucky(int n){
    static int counter = 2;

    if(n<counter)
        return 1;

    if(n%counter==0)
        return 0;

    n-=n/counter;
    counter++;

    return islucky(n);
}

int main(){
    int n;

    cin>>n;

    cout<<islucky(n)<<endl;
}
