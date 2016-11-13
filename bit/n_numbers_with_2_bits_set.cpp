#include <iostream>
using namespace std;

void printfirstnwith2bitsets(int n){

    int x=1;
    int y=0;

    while(n>0){
       y=0;
       while(y<x){
           cout<<(1<<x)+(1<<y)<<endl;
           n--;
           if(n==0)
               break;
           y++;
       }
       x++;
    }

}

int main(){
    int n=10;

    printfirstnwith2bitsets(n);

    return 0;
}
