#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int spaces=n;
    for(int i=1;i<=n;i++){

        for(int j=1;j<spaces;j++)
            cout<<" ";

        bool mode=false;
        for(int j=0;j<2*i-1;j++){
            if(mode)
                cout<<"A";
            else
                cout<<"*";

            mode=!mode;

        }
        spaces--;
        cout<<endl;


    }

    return 0;
}
