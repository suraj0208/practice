#include <iostream>

using namespace std;

float pow(float x,int y){

    if(x==0)
        return 0;

    if(y==0)
        return 1;

    float temp = pow(x,y/2);

    if(y&1){
        if(y>0){
            return x*temp*temp;
        }else{
            return (temp*temp)/x;
        }

    }
    return temp*temp;

}

int main(){
    cout<<pow(2,-4)<<endl;

    return 0;

}
