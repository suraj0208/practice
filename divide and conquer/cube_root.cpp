#include <iostream>

using namespace std;

double diff(double mid,double x){
    double temp = mid*mid*mid;

    if(temp>x)
        return temp-x;

    return x-temp;

}

double cube_root(double x){
    double e = 0.000001;

    double start=0;
    double end=x;


    while(true){
        double mid =(start+end)/2;

        double error = diff(mid,x);

        if(error<=e)
            return mid;

        if((mid*mid*mid)>x){
            end=mid;
        }else
            start=mid;

    }
}

int main(){
    int x=3;

    cout<<cube_root(x)<<endl;

    return 0;

}
