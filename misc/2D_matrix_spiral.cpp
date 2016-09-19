#include <iostream>

using namespace std;

void printSpiral(int mat[][4],int m,int n){

    int top=0,bottom=m-1,left=0,right=n-1,dir=0;

    while(top<=bottom && left<=right){

        if(dir==0){
            for(int i=left;i<=right;i++)
                cout<<mat[top][i]<<" ";
            top++;
        }else if(dir==1){
            for(int i=top;i<=bottom;i++)
                cout<<mat[i][right]<<" ";
            right--;
        }else if(dir==2){
            for(int i=right;i>=left;i--)
                cout<<mat[bottom][i]<<" ";
            bottom--;
        }else if(dir==3){
            for(int i=bottom;i>=top;i--)
                cout<<mat[i][left]<<" ";
            left++;
        }

        dir=(dir+1)%4;

    }
    cout<<endl;


}


int main(){
    int mat[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    printSpiral(mat,4,4);


    return 0;
}
