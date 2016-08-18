#include <iostream>

using namespace std;

int main(){
    int n,num=0;
    cin>>n;

    bool corp=true;

    for(int i=1;i<=n;i++){
        corp=true;
        for(int j=0;j<n-i;j++)
            cout<<" ";

        for(int j=0;j<2*i-1;j++){
            if(corp){
                cout<<i;
            }else
                cout<<" ";
            corp=!corp;
        }

        cout<<endl;

    }

    return 0;
}
