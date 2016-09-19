#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

int getlevel(node* root,int data,int k){
    if(root==null)
        return -1;

    if(root->data == data){
        return k;
    }

    int d=getlevel(root->left,data,k+1);

    if(d!=-1)
        return d;

    getlevel(root->right,data,k+1);

}


int main(){
    int data[] = { 5,4,1,6,8,7,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    cout<<getlevel(root,5,0)<<endl;


    return 0;
}
