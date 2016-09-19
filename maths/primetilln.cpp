#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n+1];

    for(int i=0;i<n+1;i++){
        arr[i]=1;
    }

    for(int i=2;i<n+1;i++){
        if(arr[i]){
            for(int j=2*i;j<n+1;j+=i)
                arr[j]=0;
        }
    }

    for(int i=2;i<n+1;i++){
        if(arr[i])
            cout<<i<<" ";
    }

    cout<<endl;

    return 0;
}
