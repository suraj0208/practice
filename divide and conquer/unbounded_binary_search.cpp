#include <iostream>

using namespace std;

int f(int x) {
    return (x*x - 10*x - 20);
}

int binary_search(int low,int high){
    if(low>high)
        return -1;

    if(low==high)
        return low;

    int mid = (low+high)/2;

    if(f(mid)>0 && f(high)>0)
        return binary_search(low,mid);

    return binary_search(mid+1,high);

}

int find_first(){
    int i=1;

    while(f(i)<0)
        i*=2;

    return binary_search(i/2,i);
}

int main(){
    cout<<find_first()<<endl;

    return 0;

}
