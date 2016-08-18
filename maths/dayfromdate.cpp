#include <iostream>
using namespace std;

int getDay(int d,int m,int y){
    int arr[] = {0,3,2, 5,0,3, 5,1,4, 6,2,4};
    y-=m<3;
    return (y+y/4-y/100+y/100+arr[m-1]+d)%7;
}


int main(){



    return 0;
}
