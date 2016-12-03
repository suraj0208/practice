#include <iostream>
using namespace std;

int resetrightmostset(int n){
    return n&(n-1);
}

int main(){
    int n = 12;

    cout<<resetrightmostset(n)<<endl;

}
