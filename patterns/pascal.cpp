#include <iostream>

using namespace std;

int main(){
    int n;

    cin>>n;

    int arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            arr[i][j]=0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || i==j)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
        }
    }

    bool corp=true;
    int row=0;
    int col=0;
    for(int i=0;i<n;i++){
        corp=true;
        col=0;

        for(int j=1;j<n-i;j++)
            cout<<" ";

        for(int j=0;j<2*i+1;j++){
            if(corp)
                cout<<arr[row][col++];
            else
                cout<<" ";

            corp=!corp;
        }
        row++;
        cout<<endl;
    }

    return 0;
}
