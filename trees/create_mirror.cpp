#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

node* create_mirror(node* root){
    if(root==null)
        return null;

    node* newnode= new node;

    newnode->data=root->data;

    newnode->right=create_mirror(root->left);
    newnode->left=create_mirror(root->right);

    return newnode;

}

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
int main(){
    int data[] = { 5,4,1,6,8,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    node* mirror;
    mirror=create_mirror(root);

    inorder(mirror);


    return 0;
}
