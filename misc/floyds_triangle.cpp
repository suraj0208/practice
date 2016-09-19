#include<iostream>
#include<stdio.h>
using namespace std;

int main(){

    int n=8;
    int num=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(i>=j)
                cout<<num++<<" ";
        cout<<endl;
    }

    return 0;

}
