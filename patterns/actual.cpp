#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n+2][n+1];
    int num=1;

    bool lorr = true;
    for(int i=0;i<=n+1;i++){

        if(lorr){
            for(int j=0;j<n;j++)
                arr[i][j]=num;
            arr[i][n]=++num;
        }else{
            for(int j=n;j>0;j--)
                arr[i][j]=num;
            arr[i][0]=++num;
        }

        lorr=!lorr;

    }

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    return 0;
}
