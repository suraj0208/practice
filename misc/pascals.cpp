#include<iostream>

using namespace std;

int main(){
    int mat[6][6]={0};

    int n=6;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(j==0)
                mat[i][j]=1;
            else if(j==i){
                mat[i][j]=1;
                break;
            }
            else
                mat[i][j]=mat[i-1][j]+mat[i-1][j-1];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j)
                break;

            cout<<mat[i][j];

        }
        cout<<endl;
    }

    return 0;
}
