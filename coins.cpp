#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int table[301];
int findcoin(int s[],int n,int v){

    for(int i=0;i<=v;i++)
        table[i]=0;

    table[0]=1;
    cout<<"before"<<endl;

    for(int i=0;i<n;i++){
        for(int j=s[i];j<=v;j++){
            table[j]+=table[j-s[i]];
        }
    }
    return table[v];
}

int main() {
    int t;
    int n;
    int v;
    cin>>t;
    int arr[301];

    while(t--){
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cin>>v;

        cout<<findcoin(arr,n,v);
        break;
    }
    return 0;
}
