#include <iostream>
#include <stack>

#include "build.h"

using namespace std;

bool childrenSum(node* root){
    if(root==null)
        return true;

    if(root->left==null && root->right == null)
        return true;

    int leftsum,rightsum;

    if(root->left)
        leftsum=root->left->data;

    if(root->right)
        rightsum=root->right->data;

    if( (root->data==leftsum+rightsum )&& childrenSum(root->left) && childrenSum(root->right) )
        return true;

    return false;

}


int main(){
    int data[] = { 5,4,1,6,8,7,9,10,3};

    node* root = null;

    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0;i<n;i++){
        root=create(root,data[i]);
    }

    cout<<childrenSum(root)<<endl;

    return 0;
}
