#include <iostream>
using namespace std;

int longest_consecutive_1s(int x){
    int count =0;

    while(x!=0){
        x=x&(x<<1);
        count++;
    }
    return count;

}

int main(){
    int x=15;

    cout<<longest_consecutive_1s(x)<<endl;

    return 0;
}
