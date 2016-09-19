#include <iostream>
#include <stack>
#include "build.h"

using namespace std;

void inorder(node* root){
    stack<node*> stk;

    while(true){

        while(root!=null){
            stk.push(root);
            root=root->left;
        }

        if(stk.size()==0)
            break;

        root=stk.top();
        stk.pop();
        cout<<root->data<<" ";
        root=root->right;
    }
    cout<<endl;

}

void root_to_leaf_path(node* root, int path[], int n){
    if(!root)
        return;

    if(root->left==null && root->right==null){
        path[n]=root->data;
        for(int i=0;i<=n;i++)
            cout<<path[i]<<" ";
        cout<<endl;
        return;
    }


    path[n]=root->data;

    root_to_leaf_path(root->left,path,n+1);
    root_to_leaf_path(root->right,path,n+1);
}


int main(){

    int data[] = { 5,4,1,6,8,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }
    inorder(root);

    int path[100];

    root_to_leaf_path(root,path,0);
    return 0;
}

