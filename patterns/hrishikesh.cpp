#include<iostream>

using namespace std;

int main(){
    int n;
    int num=1;

    cin>>n;
    int x=1;

    int i=0;

    while(i<n/2){
        num=(n*x)-n+1;

        for(int j=0;j<n;j++){
            cout<<num++<<" ";
        }
        i++;
        x+=2;
        cout<<endl;
    }


    if(n&1){
        num=(n*x)-n+1;

        for(int j=0;j<n;j++){
            cout<<num++<<" ";
        }
        i++;
        cout<<endl;
    }
    x--;
    while(i<n){
        num=(n*x)-n+1;

        for(int j=0;j<n;j++){
            cout<<num++<<" ";
        }
        i++;
        x-=2;
        cout<<endl;
    }


    return 0;
}
