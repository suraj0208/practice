#include <iostream>
#include <cmath>
using namespace std;

int getMSBPos(int n){
    int pos=0;
    while(n){
        pos++;
        n=n>>1;
    }
    return pos-1;
}

int findRangeAnd(int x, int y){
    int m_x=0;
    int m_y=0;

    int result = 0;

    m_x = getMSBPos(x);
    m_y = getMSBPos(y);

    while(m_x==m_y){
        int p = pow(2,m_x);
        result+=p;

        x-=p;
        y-=p;
        m_x=getMSBPos(x);
        m_y=getMSBPos(y);
    }


    return result;

}

int main(){
    int x=10;
    int y=15;

    cout<<findRangeAnd(x,y)<<endl;

    return 0;
}
