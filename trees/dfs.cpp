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

void preorder(node* root){

    stack<node*> stk;

    while(true){

        while(root!=null){
            cout<<root->data<<" ";
            stk.push(root);
            root=root->left;
        }

        if(stk.size()==0)
            break;

        root=stk.top();
        stk.pop();
        root=root->right;
    }
    cout<<endl;
}

void inorder1(node *root){
    if(root!=null){
        inorder1(root->left);
        cout<<root->data<<" ";
        inorder1(root->right);
    }
}

int main(){

    int data[] = { 5,4,1,6,8,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }
    inorder(root);
    preorder(root);

    return 0;
}

