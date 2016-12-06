#include <iostream>
#include <cmath>
using namespace std;

int lcs(string a,string b){

    int n=a.length();
    int m=b.length();

    int t[n+1][m+1];

    for(int i=0;i<=n;i++)
        t[i][0]=0;

    for(int i=0;i<=m;i++)
        t[0][i]=0;


    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }else{
                t[i][j]=fmax(t[i-1][j],t[i][j-1]);
            }
        }

    }

    int i=n;
    int j=m;

    string lcs_str;

    int k=0;

    for(int i=0;i<=n;i++){

        for(int j=0;j<=m;j++){
            cout<<t[i][j]<<" ";
        }

        cout<<endl;

    }

    while(i!=0 && j!=0){
        int current = t[i][j];
        if(current==t[i-1][j-1]+1 && a[i-1]==b[j-1]){
            lcs_str[k++]=a[i-1];
            i--;
            j--;
        }else if (current==t[i][j-1]){
            j--;
        }else{
            i--;
        }
    }

    for(i=k-1;i>=0;i--)
        cout<<lcs_str[i];

    cout<<endl;

    return t[n][m];

}


int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";

    cout<<lcs(a,b)<<endl;

    return 0;
}
