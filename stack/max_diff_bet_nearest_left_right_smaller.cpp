#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int getLeftSmaller(int* arr, int* leftsmall,int n){
    stack<int> s;

    for(int i=0;i<n;i++){

        while(!s.empty() && s.top()>=arr[i])
            s.pop();


        if(s.empty())
            leftsmall[i]=0;
        else
            leftsmall[i]=s.top();

        s.push(arr[i]);

    }
}

int getRightSmaller(int* arr, int* rightsmall,int n){
    stack<int> s;

    for(int i=n-1;i>=0;i--){

        while(!s.empty() && s.top()>=arr[i])
            s.pop();


        if(s.empty())
            rightsmall[i]=0;
        else
            rightsmall[i]=s.top();

        s.push(arr[i]);

    }


}

int main(){
    int arr[] = {2, 4, 8, 7, 7, 9, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int leftsmall[10];
    int rightsmall[10];

    getLeftSmaller(arr,leftsmall,n);
    getRightSmaller(arr,rightsmall,n);

    for(int i=0;i<n;i++)
        cout<<leftsmall[i]<<" ";

    cout<<endl;

    for(int i=0;i<n;i++)
        cout<<rightsmall[i]<<" ";

    cout<<endl;

    int res=-1;

    for(int i=0;i<n;i++)
        res=fmax(res,abs(leftsmall[i]-rightsmall[i]));

    cout<<res<<endl;

    return 0;
}
