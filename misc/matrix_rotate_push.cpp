#include <iostream>
#include <sstream>

using namespace std;

/* 0 0 0
     * 0 0 0
     * 1 1 1
     *
     * 1 0 0
     * 1 0 0
     * 1 0 0
*/

void shiftdownx(char* mat,int i,int j, int n){
    if(i<0 || i+1>=n)
        return;

    if(*((mat+i*n)+j)=='x' && *((mat+(i+1)*n)+j)=='o'){
        *((mat+(i+1)*n)+j)='x';
        *((mat+i*n)+j)='o';
        shiftdownx(mat,i-1,j,n);
    }

    shiftdownx(mat,i+1,j,n);

}
int main(){
    int n;

    cin>>n;

    char mat[n][n];
    char rot[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    for(int i=n-1;i>=0;i--){

        for(int j=0;j<n;j++){
            rot[j][(n-1)-i]=mat[i][j];
        }

    }

    cout<<endl;

    for(int i=0;i<n;i++){
        shiftdownx((char*)rot,0,i,n);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<rot[i][j]<<" ";
        }
        cout<<endl;
    }

    /*ostringstream ss;
    int temp=1234;
    ss<<temp;
    cout<<ss.str()<<endl;*/

    return 0;
}

