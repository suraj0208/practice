#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

bool kdistance(node* root,int k){
    if(root==null)
        return null;

    if(k==0){
        cout<<root->data<<endl;
    }

    kdistance(root->left,k-1);
    kdistance(root->right,k-1);


}


int main(){
    int data[] = { 5,4,1,6,8,7,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    kdistance(root,3);


    return 0;
}
