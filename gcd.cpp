#include <iostream>

using namespace std;

int findgcd(int a,int b){
    if(a==0)
        return b;

    if(b==0)
        return a;

    int rem;

    if(a>b){
        rem=a%b;
        return findgcd(rem,b);
    }
    else{
        rem=b%a;
        return findgcd(rem,a);
    }

}

int main(){
    int a;
    int b;

    cin>>a>>b;

    cout<<findgcd(a,b)<<endl;

    return 0;
}
