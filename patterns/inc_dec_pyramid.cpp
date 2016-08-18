#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int spaces=n;

    for(int i=1;i<=n;i++){
        int num=i;


        for(int j=1;j<spaces;j++)
            cout<<" ";

        for(int j=0;j<i;j++)
            cout<<num++;

        num--;num--;

        for(int j=1;j<i;j++)
            cout<<num--;

        spaces--;
        cout<<endl;
    }



    return 0;
}
