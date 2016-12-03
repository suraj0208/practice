#include <iostream>
using namespace std;

int getsmallestCounter(int x,int y,int z){
    int c=0;

    while(x && y && z){
        x--;
        y--;
        z--;
        c++;
    }

    return c;

}

int getsmallestDivision(int x,int y,int z){

    if(!(x/y))
       return !(x/z)? x : z;

    return !(y/z)? y:z;

}


int main(){

    cout<<getsmallestDivision(12,15,5)<<endl;
    cout<<getsmallestCounter(12,15,5)<<endl;


    return 0;
}
