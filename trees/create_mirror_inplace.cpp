#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

void create_mirror_inplace(node* root){
    if(root==null)
        return ;

    create_mirror_inplace(root->left);
    create_mirror_inplace(root->right);

    node* temp = root->left;
    root->left = root->right;
    root->right = temp;

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

    create_mirror_inplace(root);

    inorder(root);


    return 0;
}
