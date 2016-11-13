#include <iostream>
using namespace std;

void findCummulative(int a[][3],int m, int n){
    int count[m+1][n+1];
    int row[m+1][n+1];

    for(int i=1;i<=m;i++){
        count[i][0]=0;
        count[0][i]=0;
        row[i][0]=0;
        row[0][i]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){\
            count[i][j]=count[i][j-1]+a[i][j];
            row[i][j]=row[i-1][j]+count[i][j];
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<row[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    int m;

    cin>>m;
    cin>>n;

    int arr[m+1][3];

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }

    findCummulative(arr,m,n);

    return 0;
}
